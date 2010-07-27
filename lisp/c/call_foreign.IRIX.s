	.set	noreorder

	.ent	i_call_foreign
	.globl	i_call_foreign
i_call_foreign:
	.globl	f_call_foreign
f_call_foreign:
	.frame	$sp,8,$31
	.mask	0x80000000,-4
	subu	$sp,$sp,8
	sw	$16,0($sp)
	sw	$31,4($sp)
	move	$16,$sp
	move	$25,$4
	move	$8,$6
	addu	$9,$5,1
	sra	$9,$9,1
	sll	$9,$9,3
	subu	$sp,$sp,$9
	beqz	$5,.L0
	subu	$5,$5,1
	beqz	$5,.L1
	subu	$5,$5,1
	beqz	$5,.L2
	subu	$5,$5,1
	beqz	$5,.L3
	subu	$5,$5,1
	beqz	$5,.L4
	la	$9,16($8)
	la	$10,16($sp)
.L5:
	lw	$11,0($9)
	addu	$9,$9,4
	sw	$11,0($10)
	addu	$10,$10,4
	subu	$5,$5,1
	bgtu	$5,0,.L5
.L4:
	lw	$7,12($8)
	l.d	$f14,8($8)
.L3:
	lw	$6,8($8)
.L2:
	lw	$5,4($8)
	l.d	$f12,0($8)
.L1:
	lw	$4,0($8)
.L0:
	jal	$25
	nada
	move	$sp,$16
	lw	$16,0($sp)
	lw	$31,4($sp)
	addu	$sp,8
	j	$31
	.end	i_call_foreign
