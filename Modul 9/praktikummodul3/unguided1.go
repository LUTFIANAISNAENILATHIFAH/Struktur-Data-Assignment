// Lutfiana Isnaeni Lathifah
// 2311102165

package main

import (
	"fmt"
)

// Fungsi untuk menghitung faktorial
func factorial(n int) int {
	if n == 0 || n == 1 {
		return 1
	}
	result := 1
	for i := 2; i <= n; i++ {
		result *= i
	}
	return result
}

// Fungsi untuk menghitung permutasi P(n, r)
func permutation(n, r int) int {
	if r > n {
		return 0
	}
	return factorial(n) / factorial(n-r)
}

// Fungsi untuk menghitung kombinasi C(n, r)
func combination(n, r int) int {
	if r > n {
		return 0
	}
	return factorial(n) / (factorial(r) * factorial(n-r))
}

func main() {
	// Input
	var a, b, c, d int
	fmt.Print("Masukkan nilai a, b, c, d: ")
	fmt.Scan(&a, &b, &c, &d)

	// Baris pertama: permutasi dan kombinasi dari a dan c
	Pac := permutation(a, c)
	Cac := combination(a, c)

	// Baris kedua: permutasi dan kombinasi dari b dan d
	Pbd := permutation(b, d)
	Cbd := combination(b, d)

	// Output
	fmt.Println(Pac, Cac)
	fmt.Println(Pbd, Cbd)
}
