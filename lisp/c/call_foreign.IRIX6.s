	.set	noreorder
	.set	noat

	.ent	i_call_foreign
	.globl	i_call_foreign
i_call_foreign:
	.globl	f_call_foreign
f_call_foreign:
	.frame	$sp,263525380,$31
	.mask	0x80000000,-8
	daddiu	$sp,$sp,-32
	sd	$gp,8($sp)
	lui	$1,%hi(%neg(%gp_rel(i_call_foreign+0)))
	sd	$16,16($sp)
	addiu	$1,$1,%lo(%neg(%gp_rel(i_call_foreign+0)))
	sd	$31,24($sp)
	daddu	$gp,$1,$25
	move	$25,$4
	move	$12,$6
	move	$16,$sp
	beqz	$5,.L0
	daddiu	$5,$5,-1
	beqz	$5,.L1
	daddiu	$5,$5,-1	
	beqz	$5,.L2
	daddiu	$5,$5,-1	
	beqz	$5,.L3
	daddiu	$5,$5,-1	
	beqz	$5,.L4
	daddiu	$5,$5,-1	
	beqz	$5,.L5
	daddiu	$5,$5,-1	
	beqz	$5,.L6
	daddiu	$5,$5,-1	
	beqz	$5,.L7
	daddiu	$5,$5,-1	
	beqz	$5,.L8
	daddiu	$13,$5,1
	dsra	$13,$13,1
	dsll	$13,$13,4
	dsubu	$13,$sp,$13
	daddiu	$14,$12,64
	move	$sp,$13
.L9:
	ld	$15,0($14)
	daddiu	$14,$14,8
	sd	$15,0($13)
	daddiu	$13,$13,8
	daddiu	$5,$5,-1
	bgtu	$5,0,.L9
.L8:
	ld	$11,56($12)
	ldc1	$f19,56($12)
.L7:
	ld	$10,48($12)
	ldc1	$f18,48($12)
.L6:
	ld	$9,40($12)
	ldc1	$f17,40($12)
.L5:
	ld	$8,32($12)
	ldc1	$f16,32($12)
.L4:
	ld	$7,24($12)
	ldc1	$f15,24($12)
.L3:
	ld	$6,16($12)
	ldc1	$f14,16($12)
.L2:
	ld	$5,8($12)
	ldc1	$f13,8($12)
.L1:
	ld	$4,0($12)
	ldc1	$f12,0($12)
.L0:
	jal	$25
	nada
	move	$sp,$16
	ld	$31,24($sp)
	ld	$16,16($sp)
	ld	$gp,8($sp)
	daddiu	$sp,$sp,32
	j	$31
	.end	i_call_foreign
