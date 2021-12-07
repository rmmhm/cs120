	# array.s -- a simple program demonstrating
	# an array, and a while loop in MIPS.
	# 
	.data
x:	.word 10
	.word 55
	.word 73
	.word 27
	.word 44
	.word 0

prompt:	.asciiz "The total of the array is :"

	.text
main:
	# s0 is the pointer to the array
	la $s0, x

	# Set s1 to zero.  We'll use this
	# to compute a total
	add $s1, $0, $0

	# Each time around the loop, we load
	# an element from the array into register
	# t2
loop:	lw $t2, 0($s0)
	beq $t2, $0, done

	# Add the value to our running total
	add $s1, $s1, $t2

	# Move the pointer to the next element
	# of the array.  Note that we add 4, because
	# every word is 4 bytes.
	add $s0, $s0, 4

	# Back to the top of the loop
	j loop

	# Here's the end of the loop.  Print
	# the total, and then halt the machine
done:
	li $v0, 4
	la $a0, prompt
	syscall

	# Now print the number:
	li $v0, 1
	addi $a0, $s1, 0
	syscall

	# Halt the machine
	li $v0, 10
	syscall