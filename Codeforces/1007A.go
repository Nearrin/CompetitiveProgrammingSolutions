package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	sort.Ints(a)
	b := make([]int, n)
	copy(b, a)
	ans := 0
	for i := 0; i < n; i++ {
		for len(b) != 0 && b[0] <= a[i] {
			b = b[1:]
		}
		if len(b) != 0 {
			ans += 1
			b = b[1:]
		}
	}
	fmt.Printf("%d\n", ans)
}
