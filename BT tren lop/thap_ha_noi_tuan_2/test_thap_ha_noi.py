"""Chay: python test_thap_ha_noi.py (can g++ tren PATH)."""
from pathlib import Path
import re
import subprocess
import tempfile


def kiem_tra_cac_buoc(so_dia, output):
    cac_dong = output.splitlines()
    assert cac_dong[-1] == f"Tong so buoc: {2 ** so_dia - 1}"
    assert len(cac_dong) - 1 == 2 ** so_dia - 1
    cac_cot = {"A": list(range(so_dia, 0, -1)), "B": [], "C": []}
    for dong in cac_dong[:-1]:
        ket_qua = re.fullmatch(r"Dia (\d+): ([ABC]) -> ([ABC])", dong)
        assert ket_qua, dong
        dia, nguon, dich = ket_qua.groups()
        dia = int(dia)
        assert nguon != dich
        assert cac_cot[nguon] and cac_cot[nguon][-1] == dia
        assert not cac_cot[dich] or cac_cot[dich][-1] > dia
        cac_cot[nguon].pop()
        cac_cot[dich].append(dia)
    assert not cac_cot["A"] and not cac_cot["B"]
    assert cac_cot["C"] == list(range(so_dia, 0, -1))


def main():
    thu_muc = Path(__file__).resolve().parent
    ket_qua_hai_cach = []
    with tempfile.TemporaryDirectory() as tam:
        for ten_file in ("de_quy", "khu_de_quy"):
            chuong_trinh = Path(tam) / f"{ten_file}.exe"
            subprocess.run(["g++", "-std=c++17", "-Wall", "-Wextra", "-pedantic",
                            str(thu_muc / f"{ten_file}.cpp"), "-o", str(chuong_trinh)], check=True)
            ket_qua_mot_cach = []
            for so_dia in range(13):
                lan_chay = subprocess.run([str(chuong_trinh)], input=f"{so_dia}\n",
                                          text=True, capture_output=True, timeout=10)
                assert lan_chay.returncode == 0, lan_chay.stderr
                kiem_tra_cac_buoc(so_dia, lan_chay.stdout)
                ket_qua_mot_cach.append(lan_chay.stdout)
            # Kiem tra bien tren bang luong dong, khong giu trieu buoc trong bo nho.
            with subprocess.Popen([str(chuong_trinh)], stdin=subprocess.PIPE,
                                  stdout=subprocess.PIPE, text=True) as tien_trinh:
                tien_trinh.stdin.write("20\n")
                tien_trinh.stdin.close()
                so_dong = 0
                for dong in tien_trinh.stdout:
                    so_dong += 1
                assert tien_trinh.wait(timeout=10) == 0
                assert so_dong == 2 ** 20
                assert dong == "Tong so buoc: 1048575\n"
            for du_lieu in ("-1\n", "21\n", "abc\n", "2.5\n", "3 4\n", "", "999999999999\n"):
                lan_chay = subprocess.run([str(chuong_trinh)], input=du_lieu,
                                          text=True, capture_output=True, timeout=10)
                assert lan_chay.returncode == 1
                assert lan_chay.stdout == "So dia phai la so nguyen tu 0 den 20.\n"
            ket_qua_hai_cach.append(ket_qua_mot_cach)
    assert ket_qua_hai_cach[0] == ket_qua_hai_cach[1]
    assert ket_qua_hai_cach[0][2] == (
        "Dia 1: A -> B\nDia 2: A -> C\nDia 1: B -> C\nTong so buoc: 3\n")
    print("PASS: 42 lan chay; buoc di hop le, so buoc toi thieu, hai cach cho cung ket qua.")


if __name__ == "__main__":
    main()
