// Lutfiana Isnaeni Lathifah
// 2311102165

package main

import (
	"fmt"
)

// Fungsi f(x) = x^2
func f(x int) int {
	return x * x
}

// Fungsi g(x) = x - 2
func g(x int) int {
	return x - 2
}

// Fungsi h(x) = x + 1
func h(x int) int {
	return x + 1
}

// Fungsi untuk menghitung komposisi f(g(h(x)))
func fogoh(x int) int {
	return f(g(h(x)))
}

// Fungsi untuk menghitung komposisi g(h(f(x)))
func gohof(x int) int {
	return g(h(f(x)))
}

// Fungsi untuk menghitung komposisi h(f(g(x)))
func hofog(x int) int {
	return h(f(g(x)))
}

func main() {
	// Input tiga nilai a, b, c
	var a, b, c int
	fmt.Print("Masukkan nilai a, b, c: ")
	fmt.Scan(&a, &b, &c)

	// Baris pertama: f(g(h(a)))
	fmt.Println(fogoh(a))

	// Baris kedua: g(h(f(b)))
	fmt.Println(gohof(b))

	// Baris ketiga: h(f(g(c)))
	fmt.Println(hofog(c))
}
