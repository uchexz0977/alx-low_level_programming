#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char e_ident);
void print_abi(unsigned char e_ident);
void print_type(unsigned int e_type, unsigned char e_ident);
void print_entry(unsigned long int e_entry, unsigned char e_ident);
void close_elf(int elf);

void check_elf(unsigned char *e_ident)
{
    for (int index = 0; index < EI_NIDENT; index++)
    {
        if (e_ident[index] != ELFMAG[index])
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

void print_magic(unsigned char *e_ident)
{
    printf(" Magic: ");
    for (int index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", e_ident[index]);
        if (index < EI_NIDENT - 1)
            printf(" ");
    }
    printf("\n");
}

void print_class(unsigned char *e_ident)
{
    printf(" Class: ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("Invalid class\n");
    }
}

void print_data(unsigned char *e_ident)
{
    printf(" Data: ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("Invalid data encoding\n");
    }
}

void print_version(unsigned char e_ident)
{
    printf(" Version: %d\n", e_ident);
}

void print_abi(unsigned char e_ident)
{
    printf(" OS/ABI: ");
    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    // Add cases for other OS/ABI values here
    default:
        printf("Unknown OS/ABI\n");
    }
}

void print_type(unsigned int e_type, unsigned char e_ident)
{
    printf(" Type: ");
    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("Unknown type\n");
    }
}

void print_entry(unsigned long int e_entry, unsigned char e_ident)
{
    printf(" Entry point address: %#lx\n", e_entry);
}

void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
        exit(1);
    }

    int elf = open(argv[1], O_RDONLY);
    if (elf == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    unsigned char e_ident[EI_NIDENT];
    if (read(elf, e_ident, EI_NIDENT) == -1)
    {
        close_elf(elf);
        dprintf(STDERR_FILENO, "Error: Could not read ELF identifier\n");
        exit(98);
    }

    check_elf(e_ident);
    printf("ELF Header:\n");
    print_magic(e_ident);

    Elf64_Ehdr header;
    if (lseek(elf, 0, SEEK_SET) == -1 || read(elf, &header, sizeof(Elf64_Ehdr)) == -1)
    {
        close_elf(elf);
        dprintf(STDERR_FILENO, "Error: Could not read ELF header\n");
        exit(98);
    }

    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident[EI_VERSION]);
    print_abi(e_ident);
    print_type(header.e_type, e_ident);
    print_entry(header.e_entry, e_ident);

    close_elf(elf);
    return 0;
}

