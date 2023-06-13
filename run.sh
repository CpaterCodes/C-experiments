function line() {
	local columns="$COLUMNS"
	while ((columns-- > 0)); do 
		printf '%c' ":"
	done
}

echo "Building..."
make
echo "Running..."
line
./main
line
echo "Done!"

