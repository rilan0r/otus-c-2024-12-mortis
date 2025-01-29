#include <stdio.h>
#include <string.h>

unsigned cp1251_to_utf8[] = {
    [0x00] = 0x00,     // NULL
    [0x01] = 0x01,     // SOH
    [0x02] = 0x02,     // STX
    [0x03] = 0x03,     // ETX
    [0x04] = 0x04,     // EOT
    [0x05] = 0x05,     // ENQ
    [0x06] = 0x06,     // ACK
    [0x07] = 0x07,     // BEL
    [0x08] = 0x08,     // BS
    [0x09] = 0x09,     // TAB
    [0x0A] = 0x0A,     // LF
    [0x0B] = 0x0B,     // VT
    [0x0C] = 0x0C,     // FF
    [0x0D] = 0x0D,     // CR
    [0x0E] = 0x0E,     // SO
    [0x0F] = 0x0F,     // SI
    [0x10] = 0x10,     // DLE
    [0x11] = 0x11,     // DC1
    [0x12] = 0x12,     // DC2
    [0x13] = 0x13,     // DC3
    [0x14] = 0x14,     // DC4
    [0x15] = 0x15,     // NAK
    [0x16] = 0x16,     // SYN
    [0x17] = 0x17,     // ETB
    [0x18] = 0x18,     // CAN
    [0x19] = 0x19,     // EM
    [0x1A] = 0x1A,     // SUB
    [0x1B] = 0x1B,     // ESC
    [0x1C] = 0x1C,     // FS
    [0x1D] = 0x1D,     // GS
    [0x1E] = 0x1E,     // RS
    [0x1F] = 0x1F,     // US
    [0x20] = 0x20,     // Space
    [0x21] = 0x21,     // !
    [0x22] = 0x22,     // "
    [0x23] = 0x23,     // #
    [0x24] = 0x24,     // $
    [0x25] = 0x25,     // %
    [0x26] = 0x26,     // &
    [0x27] = 0x27,     // '
    [0x28] = 0x28,     // (
    [0x29] = 0x29,     // )
    [0x2A] = 0x2A,     // *
    [0x2B] = 0x2B,     // +
    [0x2C] = 0x2C,     // ,
    [0x2D] = 0x2D,     // -
    [0x2E] = 0x2E,     // .
    [0x2F] = 0x2F,     // /
    [0x30] = 0x30,     // 0
    [0x31] = 0x31,     // 1
    [0x32] = 0x32,     // 2
    [0x33] = 0x33,     // 3
    [0x34] = 0x34,     // 4
    [0x35] = 0x35,     // 5
    [0x36] = 0x36,     // 6
    [0x37] = 0x37,     // 7
    [0x38] = 0x38,     // 8
    [0x39] = 0x39,     // 9
    [0x3A] = 0x3A,     // :
    [0x3B] = 0x3B,     // ;
    [0x3C] = 0x3C,     // <
    [0x3D] = 0x3D,     // =
    [0x3E] = 0x3E,     // >
    [0x3F] = 0x3F,     // ?
    [0x40] = 0x40,     // @
    [0x41] = 0x41,     // A
    [0x42] = 0x42,     // B
    [0x43] = 0x43,     // C
    [0x44] = 0x44,     // D
    [0x45] = 0x45,     // E
    [0x46] = 0x46,     // F
    [0x47] = 0x47,     // G
    [0x48] = 0x48,     // H
    [0x49] = 0x49,     // I
    [0x4A] = 0x4A,     // J
    [0x4B] = 0x4B,     // K
    [0x4C] = 0x4C,     // L
    [0x4D] = 0x4D,     // M
    [0x4E] = 0x4E,     // N
    [0x4F] = 0x4F,     // O
    [0x50] = 0x50,     // P
    [0x51] = 0x51,     // Q
    [0x52] = 0x52,     // R
    [0x53] = 0x53,     // S
    [0x54] = 0x54,     // T
    [0x55] = 0x55,     // U
    [0x56] = 0x56,     // V
    [0x57] = 0x57,     // W
    [0x58] = 0x58,     // X
    [0x59] = 0x59,     // Y
    [0x5A] = 0x5A,     // Z
    [0x5B] = 0x5B,     // [
    [0x5C] = 0x5C,     // Backslash
    [0x5D] = 0x5D,     // ]
    [0x5E] = 0x5E,     // ^
    [0x5F] = 0x5F,     // _
    [0x60] = 0x60,     // `
    [0x61] = 0x61,     // a
    [0x62] = 0x62,     // b
    [0x63] = 0x63,     // c
    [0x64] = 0x64,     // d
    [0x65] = 0x65,     // e
    [0x66] = 0x66,     // f
    [0x67] = 0x67,     // g
    [0x68] = 0x68,     // h
    [0x69] = 0x69,     // i
    [0x6A] = 0x6A,     // j
    [0x6B] = 0x6B,     // k
    [0x6C] = 0x6C,     // l
    [0x6D] = 0x6D,     // m
    [0x6E] = 0x6E,     // n
    [0x6F] = 0x6F,     // o
    [0x70] = 0x70,     // p
    [0x71] = 0x71,     // q
    [0x72] = 0x72,     // r
    [0x73] = 0x73,     // s
    [0x74] = 0x74,     // t
    [0x75] = 0x75,     // u
    [0x76] = 0x76,     // v
    [0x77] = 0x77,     // w
    [0x78] = 0x78,     // x
    [0x79] = 0x79,     // y
    [0x7A] = 0x7A,     // z
    [0x7B] = 0x7B,     // {
    [0x7C] = 0x7C,     // |
    [0x7D] = 0x7D,     // }
    [0x7E] = 0x7E,     // ~
    [0x7F] = 0x7F,     // DEL
    [0xC0] = 0xD090,  // �
    [0xC1] = 0xD091,  // �
    [0xC2] = 0xD092,  // �
    [0xC3] = 0xD093,  // �
    [0xC4] = 0xD094,  // �
    [0xC5] = 0xD095,  // �
    [0xC6] = 0xD096,  // �
    [0xC7] = 0xD097,  // �
    [0xC8] = 0xD098,  // �
    [0xC9] = 0xD099,  // �
    [0xCA] = 0xD09A,  // �
    [0xCB] = 0xD09B,  // �
    [0xCC] = 0xD09C,  // �
    [0xCD] = 0xD09D,  // �
    [0xCE] = 0xD09E,  // �
    [0xCF] = 0xD09F,  // �
    [0xD0] = 0xD0A0,  // �
    [0xD1] = 0xD0A1,  // �
    [0xD2] = 0xD0A2,  // �
    [0xD3] = 0xD0A3,  // �
    [0xD4] = 0xD0A4,  // �
    [0xD5] = 0xD0A5,  // �
    [0xD6] = 0xD0A6,  // �
    [0xD7] = 0xD0A7,  // �
    [0xD8] = 0xD0A8,  // �
    [0xD9] = 0xD0A9,  // �
    [0xDA] = 0xD0AA,  // �
    [0xDB] = 0xD0AB,  // �
    [0xDC] = 0xD0AC,  // �
    [0xDD] = 0xD0AD,  // �
    [0xDE] = 0xD0AE,  // �
    [0xDF] = 0xD0AF,  // �
    [0xE0] = 0xD0B0,  // �
    [0xE1] = 0xD0B1,  // �
    [0xE2] = 0xD0B2,  // �
    [0xE3] = 0xD0B3,  // �
    [0xE4] = 0xD0B4,  // �
    [0xE5] = 0xD0B5,  // �
    [0xE6] = 0xD0B6,  // �
    [0xE7] = 0xD0B7,  // �
    [0xE8] = 0xD0B8,  // �
    [0xE9] = 0xD0B9,  // �
    [0xEA] = 0xD0BA,  // �
    [0xEB] = 0xD0BB,  // �
    [0xEC] = 0xD0BC,  // �
    [0xED] = 0xD0BD,  // �
    [0xEE] = 0xD0BE,  // �
    [0xEF] = 0xD0BF,  // �
    [0xF0] = 0xD180,  // �
    [0xF1] = 0xD181,  // �
    [0xF2] = 0xD182,  // �
    [0xF3] = 0xD183,  // �
    [0xF4] = 0xD184,  // �
    [0xF5] = 0xD185,  // �
    [0xF6] = 0xD186,  // �
    [0xF7] = 0xD187,  // �
    [0xF8] = 0xD188,  // �
    [0xF9] = 0xD189,  // �
    [0xFA] = 0xD18A,  // �
    [0xFB] = 0xD18B,  // �
    [0xFC] = 0xD18C,  // �
    [0xFD] = 0xD18D,  // �
    [0xFE] = 0xD18E,  // �
    [0xFF] = 0xD18F   // �
};

unsigned koi8r_to_utf8[] = {
    [0x00] = 0x00,     // NULL
    [0x01] = 0x01,     // SOH
    [0x02] = 0x02,     // STX
    [0x03] = 0x03,     // ETX
    [0x04] = 0x04,     // EOT
    [0x05] = 0x05,     // ENQ
    [0x06] = 0x06,     // ACK
    [0x07] = 0x07,     // BEL
    [0x08] = 0x08,     // BS
    [0x09] = 0x09,     // TAB
    [0x0A] = 0x0A,     // LF
    [0x0B] = 0x0B,     // VT
    [0x0C] = 0x0C,     // FF
    [0x0D] = 0x0D,     // CR
    [0x0E] = 0x0E,     // SO
    [0x0F] = 0x0F,     // SI
    [0x10] = 0x10,     // DLE
    [0x11] = 0x11,     // DC1
    [0x12] = 0x12,     // DC2
    [0x13] = 0x13,     // DC3
    [0x14] = 0x14,     // DC4
    [0x15] = 0x15,     // NAK
    [0x16] = 0x16,     // SYN
    [0x17] = 0x17,     // ETB
    [0x18] = 0x18,     // CAN
    [0x19] = 0x19,     // EM
    [0x1A] = 0x1A,     // SUB
    [0x1B] = 0x1B,     // ESC
    [0x1C] = 0x1C,     // FS
    [0x1D] = 0x1D,     // GS
    [0x1E] = 0x1E,     // RS
    [0x1F] = 0x1F,     // US
    [0x20] = 0x20,     // Space
    [0x21] = 0x21,     // !
    [0x22] = 0x22,     // "
    [0x23] = 0x23,     // #
    [0x24] = 0x24,     // $
    [0x25] = 0x25,     // %
    [0x26] = 0x26,     // &
    [0x27] = 0x27,     // '
    [0x28] = 0x28,     // (
    [0x29] = 0x29,     // )
    [0x2A] = 0x2A,     // *
    [0x2B] = 0x2B,     // +
    [0x2C] = 0x2C,     // ,
    [0x2D] = 0x2D,     // -
    [0x2E] = 0x2E,     // .
    [0x2F] = 0x2F,     // /
    [0x30] = 0x30,     // 0
    [0x31] = 0x31,     // 1
    [0x32] = 0x32,     // 2
    [0x33] = 0x33,     // 3
    [0x34] = 0x34,     // 4
    [0x35] = 0x35,     // 5
    [0x36] = 0x36,     // 6
    [0x37] = 0x37,     // 7
    [0x38] = 0x38,     // 8
    [0x39] = 0x39,     // 9
    [0x3A] = 0x3A,     // :
    [0x3B] = 0x3B,     // ;
    [0x3C] = 0x3C,     // <
    [0x3D] = 0x3D,     // =
    [0x3E] = 0x3E,     // >
    [0x3F] = 0x3F,     // ?
    [0x40] = 0x40,     // @
    [0x41] = 0x41,     // A
    [0x42] = 0x42,     // B
    [0x43] = 0x43,     // C
    [0x44] = 0x44,     // D
    [0x45] = 0x45,     // E
    [0x46] = 0x46,     // F
    [0x47] = 0x47,     // G
    [0x48] = 0x48,     // H
    [0x49] = 0x49,     // I
    [0x4A] = 0x4A,     // J
    [0x4B] = 0x4B,     // K
    [0x4C] = 0x4C,     // L
    [0x4D] = 0x4D,     // M
    [0x4E] = 0x4E,     // N
    [0x4F] = 0x4F,     // O
    [0x50] = 0x50,     // P
    [0x51] = 0x51,     // Q
    [0x52] = 0x52,     // R
    [0x53] = 0x53,     // S
    [0x54] = 0x54,     // T
    [0x55] = 0x55,     // U
    [0x56] = 0x56,     // V
    [0x57] = 0x57,     // W
    [0x58] = 0x58,     // X
    [0x59] = 0x59,     // Y
    [0x5A] = 0x5A,     // Z
    [0x5B] = 0x5B,     // [
    [0x5C] = 0x5C,     // Backslash
    [0x5D] = 0x5D,     // ]
    [0x5E] = 0x5E,     // ^
    [0x5F] = 0x5F,     // _
    [0x60] = 0x60,     // `
    [0x61] = 0x61,     // a
    [0x62] = 0x62,     // b
    [0x63] = 0x63,     // c
    [0x64] = 0x64,     // d
    [0x65] = 0x65,     // e
    [0x66] = 0x66,     // f
    [0x67] = 0x67,     // g
    [0x68] = 0x68,     // h
    [0x69] = 0x69,     // i
    [0x6A] = 0x6A,     // j
    [0x6B] = 0x6B,     // k
    [0x6C] = 0x6C,     // l
    [0x6D] = 0x6D,     // m
    [0x6E] = 0x6E,     // n
    [0x6F] = 0x6F,     // o
    [0x70] = 0x70,     // p
    [0x71] = 0x71,     // q
    [0x72] = 0x72,     // r
    [0x73] = 0x73,     // s
    [0x74] = 0x74,     // t
    [0x75] = 0x75,     // u
    [0x76] = 0x76,     // v
    [0x77] = 0x77,     // w
    [0x78] = 0x78,     // x
    [0x79] = 0x79,     // y
    [0x7A] = 0x7A,     // z
    [0x7B] = 0x7B,     // {
    [0x7C] = 0x7C,     // |
    [0x7D] = 0x7D,     // }
    [0x7E] = 0x7E,     // ~
    [0x7F] = 0x7F,     // DEL
    [0xE1] = 0xD090,  // �
    [0xE2] = 0xD091,  // �
    [0xF7] = 0xD092,  // �
    [0xE7] = 0xD093,  // �
    [0xE4] = 0xD094,  // �
    [0xE5] = 0xD095,  // �
    [0xF6] = 0xD096,  // �
    [0xFA] = 0xD097,  // �
    [0xE9] = 0xD098,  // �
    [0xEA] = 0xD099,  // �
    [0xEB] = 0xD09A,  // �
    [0xEC] = 0xD09B,  // �
    [0xED] = 0xD09C,  // �
    [0xEE] = 0xD09D,  // �
    [0xEF] = 0xD09E,  // �
    [0xF0] = 0xD09F,  // �
    [0xF2] = 0xD0A0,  // �
    [0xF3] = 0xD0A1,  // �
    [0xF4] = 0xD0A2,  // �
    [0xF5] = 0xD0A3,  // �
    [0xE6] = 0xD0A4,  // �
    [0xE8] = 0xD0A5,  // �
    [0xE3] = 0xD0A6,  // �
    [0xFE] = 0xD0A7,  // �
    [0xFB] = 0xD0A8,  // �
    [0xFD] = 0xD0A9,  // �
    [0xFF] = 0xD0AA,  // �
    [0xF9] = 0xD0AB,  // �
    [0xF8] = 0xD0AC,  // �
    [0xFC] = 0xD0AD,  // �
    [0xE0] = 0xD0AE,  // �
    [0xF1] = 0xD0AF,  // �
    [0xC1] = 0xD0B0,  // �
    [0xC2] = 0xD0B1,  // �
    [0xD7] = 0xD0B2,  // �
    [0xC7] = 0xD0B3,  // �
    [0xC4] = 0xD0B4,  // �
    [0xC5] = 0xD0B5,  // �
    [0xD6] = 0xD0B6,  // �
    [0xDA] = 0xD0B7,  // �
    [0xC9] = 0xD0B8,  // �
    [0xCA] = 0xD0B9,  // �
    [0xCB] = 0xD0BA,  // �
    [0xCC] = 0xD0BB,  // �
    [0xCD] = 0xD0BC,  // �
    [0xCE] = 0xD0BD,  // �
    [0xCF] = 0xD0BE,  // �
    [0xD0] = 0xD0BF,  // �
    [0xD2] = 0xD180,  // �
    [0xD3] = 0xD181,  // �
    [0xD4] = 0xD182,  // �
    [0xD5] = 0xD183,  // �
    [0xC6] = 0xD184,  // �
    [0xC8] = 0xD185,  // �
    [0xC3] = 0xD186,  // �
    [0xDE] = 0xD187,  // �
    [0xDB] = 0xD188,  // �
    [0xDD] = 0xD189,  // �
    [0xDF] = 0xD18A,  // �
    [0xD9] = 0xD18B,  // �
    [0xD8] = 0xD18C,  // �
    [0xDC] = 0xD18D,  // �
    [0xC0] = 0xD18E,  // �
    [0xD1] = 0xD18F   // �
};

unsigned iso8859_5_to_utf8[] = {
    [0x00] = 0x00,     // NULL
    [0x01] = 0x01,     // SOH
    [0x02] = 0x02,     // STX
    [0x03] = 0x03,     // ETX
    [0x04] = 0x04,     // EOT
    [0x05] = 0x05,     // ENQ
    [0x06] = 0x06,     // ACK
    [0x07] = 0x07,     // BEL
    [0x08] = 0x08,     // BS
    [0x09] = 0x09,     // TAB
    [0x0A] = 0x0A,     // LF
    [0x0B] = 0x0B,     // VT
    [0x0C] = 0x0C,     // FF
    [0x0D] = 0x0D,     // CR
    [0x0E] = 0x0E,     // SO
    [0x0F] = 0x0F,     // SI
    [0x10] = 0x10,     // DLE
    [0x11] = 0x11,     // DC1
    [0x12] = 0x12,     // DC2
    [0x13] = 0x13,     // DC3
    [0x14] = 0x14,     // DC4
    [0x15] = 0x15,     // NAK
    [0x16] = 0x16,     // SYN
    [0x17] = 0x17,     // ETB
    [0x18] = 0x18,     // CAN
    [0x19] = 0x19,     // EM
    [0x1A] = 0x1A,     // SUB
    [0x1B] = 0x1B,     // ESC
    [0x1C] = 0x1C,     // FS
    [0x1D] = 0x1D,     // GS
    [0x1E] = 0x1E,     // RS
    [0x1F] = 0x1F,     // US
    [0x20] = 0x20,     // Space
    [0x21] = 0x21,     // !
    [0x22] = 0x22,     // "
    [0x23] = 0x23,     // #
    [0x24] = 0x24,     // $
    [0x25] = 0x25,     // %
    [0x26] = 0x26,     // &
    [0x27] = 0x27,     // '
    [0x28] = 0x28,     // (
    [0x29] = 0x29,     // )
    [0x2A] = 0x2A,     // *
    [0x2B] = 0x2B,     // +
    [0x2C] = 0x2C,     // ,
    [0x2D] = 0x2D,     // -
    [0x2E] = 0x2E,     // .
    [0x2F] = 0x2F,     // /
    [0x30] = 0x30,     // 0
    [0x31] = 0x31,     // 1
    [0x32] = 0x32,     // 2
    [0x33] = 0x33,     // 3
    [0x34] = 0x34,     // 4
    [0x35] = 0x35,     // 5
    [0x36] = 0x36,     // 6
    [0x37] = 0x37,     // 7
    [0x38] = 0x38,     // 8
    [0x39] = 0x39,     // 9
    [0x3A] = 0x3A,     // :
    [0x3B] = 0x3B,     // ;
    [0x3C] = 0x3C,     // <
    [0x3D] = 0x3D,     // =
    [0x3E] = 0x3E,     // >
    [0x3F] = 0x3F,     // ?
    [0x40] = 0x40,     // @
    [0x41] = 0x41,     // A
    [0x42] = 0x42,     // B
    [0x43] = 0x43,     // C
    [0x44] = 0x44,     // D
    [0x45] = 0x45,     // E
    [0x46] = 0x46,     // F
    [0x47] = 0x47,     // G
    [0x48] = 0x48,     // H
    [0x49] = 0x49,     // I
    [0x4A] = 0x4A,     // J
    [0x4B] = 0x4B,     // K
    [0x4C] = 0x4C,     // L
    [0x4D] = 0x4D,     // M
    [0x4E] = 0x4E,     // N
    [0x4F] = 0x4F,     // O
    [0x50] = 0x50,     // P
    [0x51] = 0x51,     // Q
    [0x52] = 0x52,     // R
    [0x53] = 0x53,     // S
    [0x54] = 0x54,     // T
    [0x55] = 0x55,     // U
    [0x56] = 0x56,     // V
    [0x57] = 0x57,     // W
    [0x58] = 0x58,     // X
    [0x59] = 0x59,     // Y
    [0x5A] = 0x5A,     // Z
    [0x5B] = 0x5B,     // [
    [0x5C] = 0x5C,     // Backslash
    [0x5D] = 0x5D,     // ]
    [0x5E] = 0x5E,     // ^
    [0x5F] = 0x5F,     // _
    [0x60] = 0x60,     // `
    [0x61] = 0x61,     // a
    [0x62] = 0x62,     // b
    [0x63] = 0x63,     // c
    [0x64] = 0x64,     // d
    [0x65] = 0x65,     // e
    [0x66] = 0x66,     // f
    [0x67] = 0x67,     // g
    [0x68] = 0x68,     // h
    [0x69] = 0x69,     // i
    [0x6A] = 0x6A,     // j
    [0x6B] = 0x6B,     // k
    [0x6C] = 0x6C,     // l
    [0x6D] = 0x6D,     // m
    [0x6E] = 0x6E,     // n
    [0x6F] = 0x6F,     // o
    [0x70] = 0x70,     // p
    [0x71] = 0x71,     // q
    [0x72] = 0x72,     // r
    [0x73] = 0x73,     // s
    [0x74] = 0x74,     // t
    [0x75] = 0x75,     // u
    [0x76] = 0x76,     // v
    [0x77] = 0x77,     // w
    [0x78] = 0x78,     // x
    [0x79] = 0x79,     // y
    [0x7A] = 0x7A,     // z
    [0x7B] = 0x7B,     // {
    [0x7C] = 0x7C,     // |
    [0x7D] = 0x7D,     // }
    [0x7E] = 0x7E,     // ~
    [0x7F] = 0x7F,     // DEL
    [0xA0] = 0xC2A0,   // Non-breaking space
    [0xB0] = 0xD090,   // �
    [0xB1] = 0xD091,   // �
    [0xB2] = 0xD092,   // �
    [0xB3] = 0xD093,   // �
    [0xB4] = 0xD094,   // �
    [0xB5] = 0xD095,   // �
    [0xB6] = 0xD096,   // �
    [0xB7] = 0xD097,   // �
    [0xB8] = 0xD098,   // �
    [0xB9] = 0xD099,   // �
    [0xBA] = 0xD09A,   // �
    [0xBB] = 0xD09B,   // �
    [0xBC] = 0xD09C,   // �
    [0xBD] = 0xD09D,   // �
    [0xBE] = 0xD09E,   // �
    [0xBF] = 0xD09F,   // �
    [0xC0] = 0xD0A0,   // �
    [0xC1] = 0xD0A1,   // �
    [0xC2] = 0xD0A2,   // �
    [0xC3] = 0xD0A3,   // �
    [0xC4] = 0xD0A4,   // �
    [0xC5] = 0xD0A5,   // �
    [0xC6] = 0xD0A6,   // �
    [0xC7] = 0xD0A7,   // �
    [0xC8] = 0xD0A8,   // �
    [0xC9] = 0xD0A9,   // �
    [0xCA] = 0xD0AA,   // �
    [0xCB] = 0xD0AB,   // �
    [0xCC] = 0xD0AC,   // �
    [0xCD] = 0xD0AD,   // �
    [0xCE] = 0xD0AE,   // �
    [0xCF] = 0xD0AF,   // �
    [0xD0] = 0xD0B0,   // �
    [0xD1] = 0xD0B1,   // �
    [0xD2] = 0xD0B2,   // �
    [0xD3] = 0xD0B3,   // �
    [0xD4] = 0xD0B4,   // �
    [0xD5] = 0xD0B5,   // �
    [0xD6] = 0xD0B6,   // �
    [0xD7] = 0xD0B7,   // �
    [0xD8] = 0xD0B8,   // �
    [0xD9] = 0xD0B9,   // �
    [0xDA] = 0xD0BA,   // �
    [0xDB] = 0xD0BB,   // �
    [0xDC] = 0xD0BC,   // �
    [0xDD] = 0xD0BD,   // �
    [0xDE] = 0xD0BE,   // �
    [0xDF] = 0xD0BF,   // �
    [0xE0] = 0xD180,   // �
    [0xE1] = 0xD181,   // �
    [0xE2] = 0xD182,   // �
    [0xE3] = 0xD183,   // �
    [0xE4] = 0xD184,   // �
    [0xE5] = 0xD185,   // �
    [0xE6] = 0xD186,   // �
    [0xE7] = 0xD187,   // �
    [0xE8] = 0xD188,   // �
    [0xE9] = 0xD189,   // �
    [0xEA] = 0xD18A,   // �
    [0xEB] = 0xD18B,   // �
    [0xEC] = 0xD18C,   // �
    [0xED] = 0xD18D,   // �
    [0xEE] = 0xD18E,   // �
    [0xEF] = 0xD18F    // �
};

int main(int argc, char *argv[]) {

    if (argc < 4){
        printf("Incorrect args list, should be 3: source file, source encoding and output file\n");
        printf("Possible values for encodings: KOI8-R / CP-1251 / ISO8859-5\n");
        printf("Example: ./a.out input.txt KOI8-R output.txt\n");
        return 1;
    }

    if (strcmp(argv[2], "CP-1251") != 0 && strcmp(argv[2], "KOI8-R") != 0 && strcmp(argv[2], "ISO8859-5") != 0){
        printf("Possible values for encodings: KOI8-R / CP-1251 / ISO8859-5\n");
        printf("Example: ./a.out input.txt KOI8-R output.txt\n");
        return 1;
    }

    FILE *input;
    input = fopen(argv[1], "rb");
    if (!input) {
    perror("Error opening input file");
    return 1;
    }

    FILE *output;
    output = fopen(argv[3], "wb");
    if (!output) {
    perror("Error opening output file");
    return 1;
    }

    if (strcmp(argv[2], "CP-1251") == 0 ){
        int readchar;
        while ((readchar = fgetc(input)) != EOF){                       // Read fyle byte by byte until EOF
            unsigned utf8code = cp1251_to_utf8[readchar];               // Find mapping of read byte for UTF8 hex code
            unsigned char utf8bytes[2] = {0};                           // Create array to store single- or dual-byte object
            int length;

            if (utf8code <= 0x7F){
                utf8bytes[0] = (unsigned char)utf8code;                 // ASCII codes for first 127 symbols
                length = 1;
            }
            else {
                utf8bytes[0] = (unsigned char)((utf8code >> 8) & 0xFF); // Get first byte from UTF8 hex code
                utf8bytes[1] = (unsigned char)(utf8code & 0xFF);        // Get second byte from UTF8 hex code
                length = 2;
            }
            fwrite(&utf8bytes, 1, length, output);                      // Write prepared symbol to file
        }
    }
    else if (strcmp(argv[2], "KOI8-R") == 0 ){
        int readchar;
        while ((readchar = fgetc(input)) != EOF){
            unsigned utf8code = koi8r_to_utf8[readchar];
            unsigned char utf8bytes[2] = {0};
            int length;

            if (utf8code <= 0x7F){
                utf8bytes[0] = (unsigned char)utf8code;
                length = 1;
            }
            else {
                utf8bytes[0] = (unsigned char)((utf8code >> 8) & 0xFF);
                utf8bytes[1] = (unsigned char)(utf8code & 0xFF);
                length = 2;
            }
            fwrite(&utf8bytes, 1, length, output);
        }
    }
    else if (strcmp(argv[2], "ISO8859-5") == 0 ){
        int readchar;
        while ((readchar = fgetc(input)) != EOF){
            unsigned utf8code = iso8859_5_to_utf8[readchar];
            unsigned char utf8bytes[2] = {0};
            int length;

            if (utf8code <= 0x7F){
                utf8bytes[0] = (unsigned char)utf8code;
                length = 1;
            }
            else {
                utf8bytes[0] = (unsigned char)((utf8code >> 8) & 0xFF);
                utf8bytes[1] = (unsigned char)(utf8code & 0xFF);
                length = 2;
            }
            fwrite(&utf8bytes, 1, length, output);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
