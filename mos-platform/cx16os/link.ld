/* Linker script for Ben Eater's 6502 breadboard computer. */

/* Provide imaginary (zero page) registers. */
MEMORY {
  zp : ORIGIN = 0x18, LENGTH = 0x8
  ram (rw) : ORIGIN = 0xA300, LENGTH = 0xFF00 - 0xA300
}

REGION_ALIAS("c_readonly", ram)
REGION_ALIAS("c_writeable", ram)

__rc0 = 0x30;
INCLUDE imag-regs.ld
ASSERT(__rc0 == 0x30, "Inconsistent zero page map.")
ASSERT(__rc31 == 0x4f, "Inconsistent zero page map.")

REGION_ALIAS("c_writeable", ram)

SECTIONS { INCLUDE c.ld }

/* Set initial soft stack address to just above last ram address. (It grows down.) */
__stack = 0xFF00

OUTPUT_FORMAT {
  TRIM(ram)
}
