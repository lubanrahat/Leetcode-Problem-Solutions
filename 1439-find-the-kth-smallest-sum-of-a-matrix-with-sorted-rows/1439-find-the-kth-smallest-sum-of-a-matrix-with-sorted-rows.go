func kthSmallest(mat [][]int, k int) int {
	m := len(mat)

	suffixMin := make([]int, m+1)
	for i := m - 1; i >= 0; i-- {
		suffixMin[i] = suffixMin[i+1] + mat[i][0]
	}

	var count func(row, sum, target int) int
	count = func(row, sum, target int) int {
		if sum+suffixMin[row] > target {
			return 0
		}
		if row == m {
			return 1
		}

		cnt := 0
		nextMin := suffixMin[row+1]

		for _, v := range mat[row] {
			if sum+v+nextMin > target {
				break
			}

			cnt += count(row+1, sum+v, target)
			if cnt >= k {
				return k
			}
		}
		return cnt
	}

	lo := suffixMin[0]
	hi := 0
	for _, row := range mat {
		hi += row[len(row)-1]
	}

	for lo < hi {
		mid := lo + (hi-lo)/2

		if count(0, 0, mid) >= k {
			hi = mid
		} else {
			lo = mid + 1
		}
	}

	return lo
}