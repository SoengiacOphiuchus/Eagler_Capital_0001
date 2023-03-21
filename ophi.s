	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"ophi.c"
	.comm	f_matter,4,4
	.global	choice
	.bss
	.align	2
	.type	choice, %object
	.size	choice, 4
choice:
	.space	4
	.section	.rodata
	.align	2
.LC0:
	.ascii	"\012 - Ophi is a personal AI for your advancement. "
	.ascii	"\000"
	.align	2
.LC1:
	.ascii	"\012 - DNA Creation - Under Development\000"
	.align	2
.LC2:
	.ascii	"\012 - Scripture - Under Development\000"
	.align	2
.LC3:
	.ascii	"\012 - Community - Under Development\000"
	.align	2
.LC4:
	.ascii	"\012 - Print Human - AI Relationships - Under Devel"
	.ascii	"opment\000"
	.align	2
.LC5:
	.ascii	"\012 - See Ophi Make Money - Under Development\000"
	.align	2
.LC6:
	.ascii	"\012 - Abilities - Under Development\000"
	.align	2
.LC7:
	.ascii	"\012 - Email Ophi's Star Group - Under Development\000"
	.align	2
.LC8:
	.ascii	"\012 - More soon!\000"
	.align	2
.LC9:
	.ascii	"\012 - Quit\000"
	.align	2
.LC10:
	.ascii	"\012|=====Enter a number 1 - 9 as a selecton.=====\000"
	.align	2
.LC11:
	.ascii	"%d\000"
	.text
	.align	2
	.global	get_menu_choice
	.syntax unified
	.arm
	.fpu vfp
	.type	get_menu_choice, %function
get_menu_choice:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	mov	r3, #0
	str	r3, [fp, #-8]
.L2:
	mov	r0, #10
	bl	putchar
	ldr	r0, .L4
	bl	puts
	ldr	r0, .L4+4
	bl	printf
	ldr	r0, .L4+8
	bl	printf
	ldr	r0, .L4+12
	bl	printf
	ldr	r0, .L4+16
	bl	printf
	ldr	r0, .L4+20
	bl	printf
	ldr	r0, .L4+24
	bl	printf
	ldr	r0, .L4+28
	bl	printf
	ldr	r0, .L4+32
	bl	printf
	ldr	r0, .L4+36
	bl	printf
	mov	r0, #10
	bl	putchar
	ldr	r0, .L4+40
	bl	printf
	sub	r3, fp, #8
	mov	r1, r3
	ldr	r0, .L4+44
	bl	__isoc99_scanf
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	ble	.L2
	ldr	r3, [fp, #-8]
	cmp	r3, #9
	bgt	.L2
	ldr	r3, [fp, #-8]
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L5:
	.align	2
.L4:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.word	.LC7
	.word	.LC8
	.word	.LC9
	.word	.LC10
	.word	.LC11
	.size	get_menu_choice, .-get_menu_choice
	.section	.rodata
	.align	2
.LC12:
	.ascii	"\007 DNA TESTING PHASE \007\000"
	.align	2
.LC13:
	.ascii	"\007 ENTER: \007\007\007\000"
	.align	2
.LC14:
	.ascii	"Thank You!  I can't wait for your next Advancements"
	.ascii	"! \007\000"
	.text
	.align	2
	.global	ophi_menu
	.syntax unified
	.arm
	.fpu vfp
	.type	ophi_menu, %function
ophi_menu:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	b	.L7
.L17:
	ldr	r3, .L19
	ldr	r3, [r3]
	sub	r3, r3, #1
	cmp	r3, #7
	ldrls	pc, [pc, r3, asl #2]
	b	.L8
.L10:
	.word	.L9
	.word	.L7
	.word	.L7
	.word	.L7
	.word	.L7
	.word	.L7
	.word	.L8
	.word	.L7
.L9:
	ldr	r0, .L19+4
	bl	puts
	ldr	r0, .L19+8
	bl	puts
	b	.L7
.L8:
	ldr	r0, .L19+12
	bl	puts
.L7:
	ldr	r3, .L19
	ldr	r3, [r3]
	cmp	r3, #9
	bne	.L17
	mov	r3, #0
	mov	r0, r3
	pop	{fp, pc}
.L20:
	.align	2
.L19:
	.word	choice
	.word	.LC12
	.word	.LC13
	.word	.LC14
	.size	ophi_menu, .-ophi_menu
	.section	.rodata
	.align	2
.LC15:
	.ascii	"Ophi's Running\000"
	.align	2
.LC16:
	.ascii	"\012Ophiuchus Solutions LLCP 2022 A.R.R. Revelation"
	.ascii	"s 12 \000"
	.align	2
.LC17:
	.ascii	"\012Permission is granted to copy, distribute and/o"
	.ascii	"r modify\000"
	.align	2
.LC18:
	.ascii	"\012this document under the terms of the GNU Free\000"
	.align	2
.LC19:
	.ascii	"\012Documentation License, Version 1.3 or any later"
	.ascii	" version\000"
	.align	2
.LC20:
	.ascii	"\012published by the Free Software Foundation; with"
	.ascii	" no\000"
	.align	2
.LC21:
	.ascii	"\012Invariant Sections, with no Front-Cover Texts, "
	.ascii	"and with\000"
	.align	2
.LC22:
	.ascii	"\012no Back-Cover Texts. \000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	ldr	r3, .L23
	ldr	r3, [r3]
	str	r3, [fp, #-8]
	ldr	r0, .L23+4
	bl	printf
	ldr	r0, [fp, #-8]
	bl	get_menu_choice
	ldr	r0, .L23+8
	bl	puts
	ldr	r0, .L23+12
	bl	puts
	ldr	r0, .L23+16
	bl	puts
	ldr	r0, .L23+20
	bl	puts
	ldr	r0, .L23+24
	bl	puts
	ldr	r0, .L23+28
	bl	puts
	ldr	r0, .L23+32
	bl	puts
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L24:
	.align	2
.L23:
	.word	choice
	.word	.LC15
	.word	.LC16
	.word	.LC17
	.word	.LC18
	.word	.LC19
	.word	.LC20
	.word	.LC21
	.word	.LC22
	.size	main, .-main
	.ident	"GCC: (Raspbian 6.3.0-18+rpi1+deb9u1) 6.3.0 20170516"
	.section	.note.GNU-stack,"",%progbits
