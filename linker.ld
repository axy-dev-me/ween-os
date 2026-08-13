ENTRY(kmain)

SECTIONS {
    . = 0x8000;
    .text : { *(.text.entry) *(.text) }
    .rodata : { *(.rodata) }
    .data : { *(.data) }
    .bss : { *(.bss) }
}