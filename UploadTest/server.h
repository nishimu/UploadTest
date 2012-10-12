//
//  server.h
//  UploadTest
//
//  Created by 西村 俊夫 on 2012/10/09.
//  Copyright (c) 2012年 Can-I Systems. All rights reserved.
//

#ifndef UploadTest_server_h
#define UploadTest_server_h

#define SERVER_IP_ADDRESS   @"218.45.194.131"
#define SERVER_PORT         5002
#define TEST_DURATION       (10.0) // sec
#define BUF_LENGTH          2048
#define ENDMARK             0xff
#define SAMPLE_SEND_DATA    0x68,0x30,0x54,0x01,0xD4,0xE5,0x6B,0xAE,0x8A,0x8C,0x1D,0xB8,0xFD,0x19,0x91,0xDD,0x6B,0x6E,0xDD,0x60,0xD1,0x3A,0xE4,0x47,0xBA,0xAD,0x51,0xCC,0xA7,0x23,0x5B,0x1F,0x45,0x83,0xC4,0x8F,0xFC,0xAB,0x47,0xC1,0xD6,0x82,0xB7,0x1F,0x06,0x56,0xC7,0xCC,0xA8,0x50,0xEB,0x98,0x3B,0xAB,0x10,0x78,0xEB,0x41,0x39,0x1F,0x5A,0xEB,0x04,0x7B,0x1D,0x68,0xEE,0xBA,0x34,0x4E,0xBC,0x6B,0xEE,0xFA,0x31,0xF8,0x3D,0x15,0xB7,0x8C,0x8C,0x1E,0x8C,0x7B,0xAC,0x18,0x8E,0x67,0x13,0x1E,0x04,0x0F,0xCC,0xE2,0x47,0xD8,0xD6,0x83,0x1F,0xD6,0x0F,0x8F,0xF9,0x74,0xEB,0xAF,0xE3,0xF1,0xDD,0xE3,0xC0,0x8E,0x27,0x12,0xB5,0xD3,0x88,0x27,0x4E,0xA3,0xDD,0x3A,0x1E,0x8A,0x8B,0x1E,0x08,0xCF,0xF8,0xF0,0x63,0xFC,0x78,0x31,0x1F,0x93,0xA0,0x7E,0x4E,0x97,0xFE,0xCE,0xA7,0xF0,0x5D,0x0F,0x63,0xD1,0xC7,0x82,0x31,0xF6,0x3C,0xC1,0xEE,0xDD,0x44,0x77,0x9D,0x56,0xDD,0xE0,0xC7,0xD3,0xD6,0x8F,0x10,0xA3,0xA3,0xF9,0x3A,0x88,0xE8,0xFE,0xC3,0xF3,0x1D,0x2F,0xEF,0x3A,0x23,0x5B,0xC8,0x05,0x6F,0xE5,0x1F,0xCC,0x74,0x09,0x95,0xF3,0x9C,0x4C,0x18,0xFA,0xDC,0x1C,0x78,0x3B,0x11,0x1E,0xA0,0x8D,0x6F,0x8C,0x79,0xCE,0x61,0x13,0xF7,0x71,0xF8,0xF0,0xEE,0x89,0xD2,0xFE,0x46,0x0C,0xFD,0x8B,0xA5,0xFC,0xC7,0x51,0x13,0x2B,0xE6,0x69,0xFC,0x63,0xA5,0xA2,0xEB,0xF7,0x9D,0x47,0xEB,0x5D,0x11,0x33,0xF9,0x58,0xF1,0x3A,0x23,0xC2,0xD8,0x8E,0xA1,0xD4,0xFD,0x15,0x89,0x10,0xBE,0x35,0x13,0x3C,0xC1,0xC8,0x75,0x3F,0x3F,0x44,0xBD,0x7B,0xAC,0x7C,0xCE,0x2F,0x9F,0x9C,0xBB,0xA2,0x9C,0x75,0x8F,0x42,0x33,0xF3,0x38,0x23,0x81,0x42,0x20,0x7E,0x48,0x81,0xD1,0x5F,0x4F,0xE3,0xEB,0xF3,0x31,0xE2,0x26,0x0C,0x7A,0x5E,0x26,0x3D,0x11,0xD6,0xEB,0x5D,0x4F,0x8E,0xE9,0x40,0x2E,0xE6,0x41,0xF9,0x6D,0xD4,0x7E,0x4B,0xD4,0x3A,0xDB,0xCC,0xF7,0xA3,0xD1,0x6B,0x7A,0xFC,0x8C,0x19,0x90,0x72,0x3A,0xEB,0xDD,0x47,0x83,0x6E,0xBF,0x5B,0xC4,0x5E,0x3B,0xAE,0xBE,0xB5,0xD2,0xF2,0x30,0x68,0x88,0xB1,0xE8,0xD3,0xF8,0xEE,0xD4,0x3A,0xEB,0xE3,0xF0,0x66,0x70,0x57,0x83,0x99,0x62,0xA3,0x91,0x76,0x3E,0x0A,0xF1,0xEB,0x7F,0xFD,0x46,0x58,0xF5,0x1A,0xE9,0xD2,0x87,0x54,0x48,0xA8,0x9D,0x0E,0xE8,0x70,0x0E,0xA0,0x0A,0x31,0xE3,0xDF,0x5F,0x1F,0x39,0x8F,0x83,0xD7,0xAD,0xE8,0xBA,0x51,0x82,0xEB,0x6F,0x82,0xBC,0x8A,0x29,0xF2,0x31,0xF1,0x17,0x31,0xD7,0x23,0x07,0xAF,0x33,0x63,0xD7,0x44,0xBF,0xAF,0x4F,0xC4,0x75,0x1F,0xC8,0xC7,0x9F,0xEB,0xC0,0xA2,0xEF,0x1F,0x3B,0x6D,0xFA,0x2E,0x87,0xA7,0x74,0xA2,0x9D,0xD0,0xF3,0x37,0x63,0xC7,0xA8,0x01,0x0E,0xB6,0xF6,0x35,0xB1,0x0A,0x17,0xCC,0xCE,0x75,0xC0,0x45,0x68,0x31,0xF1,0x8C,0xCB,0xA1,0xC8,0xC7,0xB0,0xC8,0x7F,0xFE,0xB1,0x1F,0xFE,0xB0,0xB2,0xB1,0xE8,0xF7,0xA6,0x99,0xF4,0xC8,0x05,0x65,0x3E,0x58,0x19,0xDB,0x35,0xBB,0x0C,0x32,0x38,0x80,0xB1,0x9E,0xE0,0x57,0x28,0x8C,0xD7,0xE2,0xC3,0xBC,0x7E,0x6D,0x79,0x27,0xD9,0xA1,0x8D,0xE9,0x54,0x23,0x30,0x4A,0x3E,0x2A,0xAD,0x45,0xD8,0x4E,0x71,0xBF,0x35,0xDD,0x2D,0x01,0x76,0xF9,0x97,0x1E,0x1F,0xB5,0xD8,0x12,0x20,0x91,0xD4,0x78,0x7C,0xC7,0x65,0x7E,0xB9,0x75,0x9E,0xEC,0x61,0x19,0xE7,0x45,0x1C,0x17,0xF2,0x33,0x42,0x32,0x55,0x7F,0xF2,0x69,0xF9,0x25,0x31,0xEA,0x17,0x9F,0xBF,0x9B,0x05,0x4F,0x53,0x9A,0x3B,0x6E,0xEA,0x40,0x03,0xCD,0xFD,0xCC,0x3C,0xA7,0xE6,0x1F,0x06,0xAF,0xBB,0x7A,0xB1,0xBB,0xD7,0x6A,0xE8,0xDE,0xBB,0xD3,0xEE,0xD4,0x07,0x07,0x03,0xEF,0x41,0x81,0x18,0x3B,0x82,0x38,0x95,0x14,0x99,0x3F,0x6E,0x2D,0x1C,0x57,0x58,0xEB,0x2A,0xCD,0x76,0x9F,0xA7,0x3B,0xE1,0x82,0x81,0x7F,0x2C,0x04,0x83,0x3A,0x0C,0x4E,0x38,0x85,0xD0,0xD9,0xDA,0xD4,0x5E,0xDA,0xEA,0x8F,0x33,0xDB,0x5F,0xE9,0x70,0x82,0x8C,0xE3,0x2E,0x3D,0xAF,0x7F,0xE7,0x58,0xFE,0x60,0xA1,0x14,0x9D,0x6C,0x15,0xA1,0xD2,0x85,0xB8,0x46,0x07,0xAF,0x3C,0xF2,0xBB,0xFB,0x5F,0xC7,0xF3,0x37,0x23,0x4F,0xB9,0xEB,0xA0,0xC5,0x81,0x46,0x5F,0xE1,0x83,0xE3,0xB1,0x6F,0xCF,0xCE,0x95,0xAC,0xA6,0xDE,0x02,0xDE,0x63,0xF2,0x40,0xDB,0x11,0x0A,0x4C,0x55,0x7F,0xE7,0x90,0x29,0x8E,0x92,0x1F,0x9A,0x1F,0xDE,0x75,0xE3,0xF8,0x41,0x95,0x3A,0x67,0x71,0xFB,0x81,0x59,0x61,0x37,0xDA,0x64,0xEF,0x39,0xDF,0xD0,0x4E,0x3E,0x81,0x72,0xA0,0xEA,0x76,0xEA,0x7E,0x8D,0x56,0x5D,0xFA,0x48,0x18,0x2F,0x16,0x07,0x64,0xB0,0x7A,0x1E,0x89,0x5A,0x6F,0x99,0xCA,0x81,0x49,0xDE,0x5B,0xD5,0x70,0x03,0x65,0x0F,0x2C,0xB6,0x2E,0xBD,0x53,0x51,0x80,0xC5,0xA0,0x47,0x22,0xC7,0x21,0xB7,0x01,0x20,0xF6,0xDE,0x11,0xA3,0x64,0x74,0xA9,0x83,0x8D,0x80,0xF8,0x0A,0x64,0xF9,0x38,0x95,0x6C,0x7C,0x15,0xAC,0xEA,0xF2,0xE6,0xAB,0x53,0xFD,0x99,0x2A,0x8D,0x5B,0xBD,0x94,0x65,0xF5,0x2D,0x15,0x5C,0xA5,0xD5,0xB2,0xF2,0xD3,0x5C,0x3F,0x65,0x82,0x80,0xF2,0x7B,0x9C,0x6F,0xB2,0x91,0xA1,0x35,0x06,0x8B,0x18,0xB0,0x28,0x1B,0x52,0xAE,0x8B,0xF1,0x1E,0xFD,0xE3,0xEE,0xB9,0x36,0x1B,0x30,0x8B,0x1C,0xF0,0x16,0x68,0x24,0x1F,0xD6,0x45,0x04,0x6D,0xEE,0xE6,0xDB,0x7D,0x19,0x9F,0xF0,0x7C,0x15,0xC8,0x4A,0xC6,0xB3,0xBA,0x26,0x13,0xDC,0xA2,0xF3,0x46,0xF4,0x06,0xBF,0x64,0x14,0x16,0x30,0x57,0x8F,0xA0,0x05,0x87,0x74,0xC9,0x86,0x3D,0xAD,0xEC,0x85,0xFD,0xE5,0xC5,0x63,0xE1,0x6D,0x17,0x3B,0x83,0xEA,0x2D,0xA7,0xBD,0x01,0x1A,0xDC,0xC3,0x5A,0xFA,0x75,0x7C,0x7A,0xCC,0x8A,0x20,0x75,0x0E,0xC0,0x54,0x7A,0xAC,0xD2,0x24,0xDC,0x26,0xA1,0xCD,0x47,0x80,0x8C,0x4F,0xBA,0x2F,0xE6,0x39,0xA9,0xE0,0xED,0xB0,0x5A,0x3A,0x5B,0x5A,0x91,0x64,0x8F,0x94,0xEC,0x01,0x9C,0x32,0xD4,0x1A,0x57,0xFB,0xB6,0xEC,0x8E,0x93,0xD9,0x13,0x01,0x01,0x20,0xBF,0xC1,0x9A,0x1B,0xF6,0xD2,0xE3,0x42,0x03,0x6B,0x54,0xE2,0x69,0x04,0x85,0x94,0x48,0x60,0xAB,0x39,0x13,0x9E,0x19,0xFE,0x78,0xBA,0xB1,0xA9,0x20,0xD7,0xD1,0xC0,0x22,0xAE,0x73,0x70,0x4B,0xF5,0x5E,0x92,0xB9,0x03,0xE4,0x93,0x4A,0xA3,0x4E,0x87,0xAE,0xAB,0xD1,0x17,0x80,0xB3,0xCD,0x9D,0x44,0x49,0x4F,0xBF,0x12,0x75,0x3B,0x8C,0xEC,0x06,0x44,0x0C,0xBB,0xD0,0xBD,0xB0,0x41,0x4B,0x45,0x23,0xC3,0x5A,0x13,0xDA,0x96,0xA0,0x51,0x1F,0x7F,0x31,0x51,0x2C,0x9E,0x78,0x2E,0x34,0xB4,0x56,0xE5,0xC2,0x5A,0x44,0xBA,0x7A,0x82,0x06,0xDB,0x66,0x5B,0x79,0xF0,0x5F,0x02,0x73,0x8B,0x21,0xC2,0xB2,0x5C,0x54,0xC7,0x8F,0x1B,0xC3,0x95,0x31,0xED,0xE6,0xB5,0x18,0x3F,0x57,0x47,0x69,0xDF,0xDA,0x6F,0xEE,0x66,0xC8,0x05,0x83,0x8D,0x85,0x84,0x5E,0x0D,0x1C,0x12,0x8E,0xBD,0xEA,0x1E,0x47,0xC5,0x1B,0x0E,0xC5,0x57,0xBF,0xD9,0xC8,0x34,0x7C,0x36,0x3C,0x25,0x4F,0x26,0xAE,0x26,0xFC,0x81,0x5A,0xBB,0xFD,0x08,0x94,0x77,0x74,0x74,0xDB,0x22,0xEB,0x22,0xC1,0x22,0x87,0xB6,0x3C,0x25,0x23,0x5A,0xC1,0x78,0xDE,0xCE,0xFA,0x03,0x7D,0x65,0x5F,0x06,0xA8,0xD5,0x2C,0xD0,0x83,0xFC,0x3D,0xEB,0xCF,0x0E,0x6A,0x31,0x48,0x09,0xDF,0xD3,0x48,0xF2,0x3B,0xEB,0x9E,0xA0,0x60,0xDD,0x19,0xB8,0x33,0xC2,0xEB,0xD9,0x9B,0x47,0x8D,0x0E,0x18,0xE7,0xF4,0xEB,0x4A,0x98,0x35,0xE4,0x8B,0xE7,0x9F,0x1E,0x86,0x8F,0x80,0x76,0x02,0x46,0x8F,0xDA,0x6C,0x7B,0x07,0xE4,0x35,0xB1,0xBE,0x8A,0xD2,0x98,0xC8,0x6E,0x36,0xFD,0x85,0xC9,0x22,0x34,0x97,0x7A,0x3E,0x3C,0xAE,0x77,0x9F,0x9D,0x87,0x2E,0x95,0x71,0x6C,0xFD,0x5C,0xAF,0xE7,0x77,0x13,0xA8,0xD6,0x53,0xD6,0x46,0xF7,0x1B,0x34,0xCE,0xC4,0x48,0x17,0xAC,0x88,0xE2,0x74,0xAB,0x89,0x98,0x07,0x9D,0x39,0x7F,0xAC,0x67,0xF5,0x23,0x88,0x2E,0x8B,0xA5,0x9D,0x8A,0xDF,0x0F,0x9B,0x4A,0xDF,0xEF,0x78,0xF2,0x5E,0x71,0x97,0x46,0x72,0x83,0x54,0x58,0xFD,0xB6,0xFE,0x67,0xB2,0x68,0x4E,0xFB,0x33,0x09,0x77,0xAC,0x54,0xA8,0x35,0xCF,0xB4,0xC2,0x5B,0x17,0x09,0x35,0xD8,0xAC,0x79,0x10,0x14,0x5A,0x49,0x4B,0x5A,0x5A,0x2E,0xDE,0x45,0x11,0x6C,0xF8,0x79,0x7F,0x5D,0x18,0x45,0xED,0xB3,0xBF,0x35,0xD3,0xBF,0x43,0x0A,0xBA,0x6A,0x8E,0x87,0x2F,0xF9,0xF9,0x94,0x3C,0xFB,0x82,0x63,0xB0,0xA9,0x0C,0x0E,0xCC,0xB8,0x43,0xD9,0x33,0xAC,0xD1,0xDE,0x33,0x14,0xD3,0x1A,0xC8,0xD4,0x2A,0x84,0xA6,0x57,0x40,0xF5,0x52,0x09,0x58,0xCF,0x07,0x8D,0x25,0x3C,0x18,0xA0,0x91,0x53,0x2E,0x1D,0xB8,0x43,0xEC,0xE8,0xFC,0xCE,0xFE,0xA0,0x8B,0xCA,0x39,0x67,0xF1,0xA1,0xB7,0x54,0x2D,0x38,0x0A,0xEB,0xB7,0xFD,0xF7,0x61,0xEA,0x3B,0x02,0x6B,0x56,0x55,0xEA,0x1D,0x0F,0xCD,0xAE,0xDC,0xE1,0x9C,0x45,0xE6,0x56,0x2A,0x7E,0x58,0x2B,0xA7,0x5A,0x13,0xC0,0x0A,0x3C,0x1B,0x0C,0x8C,0x5D,0xB4,0xC2,0x37,0xA7,0x25,0x0C,0xCE,0x53,0x35,0xA1,0xC8,0x81,0xB8,0x71,0xBF,0xC3,0x75,0xBA,0x9A,0x3F,0x31,0xED,0x2D,0xFB,0x0C,0x8F,0x49,0xB5,0x72,0x10,0x14,0x69,0x97,0xED,0xC5,0xE2,0xA9,0x16,0x9A,0x39,0x52,0x3D,0xEA,0xAE,0xE4,0x64,0xCE,0x12,0xD2,0xBD,0x34,0x09,0x35,0x1E,0xCB,0xB3,0xB4,0x80,0x48,0x0C,0x01,0xE8,0xA9,0xD3,0xC5,0xDD,0x56,0x09,0x86,0x95,0xE3,0xA4,0x12,0xF4,0x36,0xB6,0x35,0xCF,0xF3,0xD7,0x22,0x3D,0x6D,0xEE,0xB4,0x74,0x76,0x75,0x9B,0x22,0x1B,0x1F,0xC0,0x6B,0x58,0xF3,0xCB,0x6B,0x5D,0x4B,0x79,0x04,0x8F,0xA1,0x78,0xC1,0xE3,0xDC,0x55,0x75,0x0A,0xBE,0x3E,0xBF,0xEC,0x86,0xDD,0xE5,0xCA,0x21,0x76,0xD5,0x8D,0x0B,0xDD,0x07,0x6F,0xB7,0x9D,0xF9,0xD2,0xD5,0x6A,0x66,0xBC,0xA6,0x8D,0x34,0x3C,0x96,0xC8,0x40,0x67,0x43,0x2D,0xE7,0xD2,0xE4,0xCB,0xB8,0xF5,0xF9,0x1A,0x5B,0x20,0x81,0xC6,0x8E,0x30,0x0A,0x96,0x63,0x6B,0x0A,0x6C,0x7F,0x2D,0x86,0x56,0x43,0xA5,0x36,0x7E,0x11,0xCA,0x6D,0xE4,0x3D,0x22,0xA3,0x4E,0x5C,0xBB,0x20,0xC3,0xA0,0x36,0xFE,0xC6,0x58,0xD7,0x8A,0x21,0x89,0x77,0xCC,0x03,0xEC,0xEC,0x73,0x47,0x76,0x4A,0x47,0xD5,0x3C,0x41,0x44,0x75,0x4A,0x6B,0x19,0xD2,0x56,0xEB,0x3F,0x4E,0xBE,0x85,0xE7,0x72,0x39,0x93,0x1E,0x57,0x2E,0xD4,0xD6,0x47,0x41,0xEE,0x21,0xB7,0xCF,0x47,0x84,0x15,0xB4,0x23,0x31,0x62,0x23,0xCC,0x7F,0x1E,0xAB,0x8A,0xE3,0xCA,0x5C,0x6E,0xB4,0xFE,0x4B,0xB8,0x6D,0xCC,0x45,0x5D,0xA3,0x42,0x91,0xF8,0x7F,0xB9,0x97,0xD9,0x06,0x75,0x7F,0xAF,0x47,0x8F,0x22,0x0C,0x6C,0xCE,0x6C,0x05,0x01,0x23,0x15,0x4F,0xBF,0x6D,0xB6,0x64,0xD5,0xBE,0x21,0xF5,0x50,0xFC,0x81,0x60,0x5B,0xD5,0xBE,0xB9,0x9C,0xAB,0xA5,0x9E,0x27,0x38,0x28,0x4D,0x9F,0xB3,0x11,0x01,0x9E,0xD9,0x73,0xE0,0xF3,0x17,0x97,0x6F,0x54,0xBC,0x03,0xA4,0xE1,0xD0,0x09,0x7F,0x65,0x59,0xA1,0xFA,0xB9,0xAF,0x72,0x85,0x96,0x17,0x8C,0x73,0x39,0xF0,0x10,0x7C,0xAB,0xC6,0xD5,0x2F,0x37,0xF9,0xA8,0xCB,0xB4,0xA6,0x8F,0xD8,0x93,0x21,0x04,0xD3,0xBD,0x0D,0x72,0x94,0x19,0x3C,0x36,0xC6,0xD5,0x1B,0xEE,0x45,0xF2,0xDC,0x05,0xAE,0xB6,0x96,0x81,0xF0,0xB4,0xBD,0xCA,0xC1,0xA0,0xCF,0x6B,0x28,0xD7,0x11,0x9E,0x73,0xD1,0x4E,0x40,0xBD,0x0E,0x07,0x86,0x03,0x97,0x11,0x9C,0xCB,0x5B,0xE1,0x0D,0x24,0x2D,0x10,0xA9,0x0A,0xC0,0xE0,0x5A,0x73,0x4E,0x8C,0xE3,0x8E,0x93,0x73,0x3C,0x67,0x96,0x0B,0x4A,0xEF,0xAF,0x64,0xE1,0xEF,0x32,0x89,0x6C,0x9E,0x0E,0x88,0x37,0x51,0xE2,0x1F,0x46,0xE7,0xB1,0x91,0xA4,0x6E,0x6C,0xA7,0x86,0xAC,0xDB,0x91,0xD8,0xE7,0x60,0xC4,0x55,0x12,0xE8,0x05,0x3D,0x7E,0x71,0xF7,0x51,0x8A,0xF8,0xDB,0xBD,0x8C,0xF1,0x67,0xF7,0x37,0x92,0xF9,0x3F,0x73,0x85,0xDC,0x7A,0xD6,0x67,0x3B,0x76,0x59,0xA0,0xBF,0xB6,0x5B,0xBA,0x73,0x44,0xA5,0x81,0x26,0xA9,0xF3,0x64,0xA6,0xA9,0xD3,0x78,0x20,0xA1,0xDC,0xF6,0x21,0xBD,0x06,0x40,0x6E,0xB9,0xBC,0x3F,0x0A,0x20,0x17,0x19,0x3C,0x73,0xE6,0x51,0x40,0xBA,0x05,0x98,0x7D,0xEB,0x10,0x82,0x0B,0x43,0x43,0xF4,0xC8,0x91,0x99,0xF7,0xD8,0x71,0x86,0x46,0x42,0xD0,0xFD,0xEF,0x7F,0x31,0x21
#endif