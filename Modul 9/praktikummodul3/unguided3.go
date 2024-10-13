// Lutfiana Isnaeni Lathifah
// 2311102165

package main

import (
	"fmt"
	"math"
)

// Fungsi untuk menghitung jarak antara dua titik
func jarak(x1, y1, x2, y2 float64) float64 {
	return math.Sqrt(math.Pow(x1-x2, 2) + math.Pow(y1-y2, 2))
}

// Fungsi untuk mengecek apakah titik (x, y) berada di dalam lingkaran
func diDalam(cx, cy, r, x, y float64) bool {
	return jarak(cx, cy, x, y) <= r
}

func main() {
	// Input dari pengguna
	var cx1, cy1, r1 float64 // Koordinat dan radius lingkaran 1
	var cx2, cy2, r2 float64 // Koordinat dan radius lingkaran 2
	var x, y float64         // Koordinat titik sembarang

	fmt.Println("Masukkan koordinat pusat lingkaran 1 (cx1, cy1) dan radius r1:")
	fmt.Scan(&cx1, &cy1, &r1)
	fmt.Println("Masukkan koordinat pusat lingkaran 2 (cx2, cy2) dan radius r2:")
	fmt.Scan(&cx2, &cy2, &r2)
	fmt.Println("Masukkan koordinat titik sembarang (x, y):")
	fmt.Scan(&x, &y)

	// Cek posisi titik terhadap lingkaran 1 dan lingkaran 2
	diDalamLingkaran1 := diDalam(cx1, cy1, r1, x, y)
	diDalamLingkaran2 := diDalam(cx2, cy2, r2, x, y)

	// Output hasil
	if diDalamLingkaran1 && diDalamLingkaran2 {
		fmt.Println("Titik di dalam lingkaran 1 dan 2")
	} else if diDalamLingkaran1 {
		fmt.Println("Titik di dalam lingkaran 1")
	} else if diDalamLingkaran2 {
		fmt.Println("Titik di dalam lingkaran 2")
	} else {
		fmt.Println("Titik di luar lingkaran 1 dan 2")
	}
}
