function line() {
	local columns="$COLUMNS"
	while ((columns-- > 0)); do 
		printf '%c' "-"
	done
}

echo "Building..."
make objects/dyn_structures.o
make objects/main.o
make
echo "Running..."
line
./main
line
echo "Done!"

