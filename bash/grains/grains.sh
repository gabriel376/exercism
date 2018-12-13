MAX=64
MIN=1

function count() {
	if [[ $1 == "total" ]]; then
		echo "(2^$MAX)-1" | bc
		exit 0

	elif [[ $1 -lt $MIN || $1 -gt $MAX ]]; then
		echo "Error: invalid input"
		exit 1

	else
		echo "2^($1-1)" | bc
		exit 0
	fi
}

count $1
