MAX=64
MIN=1

function count() {
	if [[ $1 == "total" ]]; then
		# TODO:  use << here without overflow
		printf "%llu\n" $((2**$MAX-1))
		exit 0

	elif [[ $1 -lt $MIN || $1 -gt $MAX ]]; then
		printf "%s\n" "Error: invalid input"
		exit 1

	# TODO: remove this condition and
	# let it go on else clause
	elif [[ $1 -eq $MIN ]]; then
		printf "%llu\n" $MIN
		exit 0

	else
		printf "%llu\n" $((2 << ($1-2)))
		exit 0
	fi
}

count $1