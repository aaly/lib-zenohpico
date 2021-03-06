/*
 * Copyright (c) 2017, 2021 ADLINK Technology Inc.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Apache License, Version 2.0
 * which is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
 *
 * Contributors:
 *   ADLINK zenoh team, <zenoh@adlink-labs.tech>
 */

#ifndef _ZENOH_PICO_PROTOCOL_PRIVATE_IOBUF_H
#define _ZENOH_PICO_PROTOCOL_PRIVATE_IOBUF_H

#include <stdint.h>
#include "zenoh-pico/utils/collections.h"
#include "zenoh-pico/utils/types.h"
#include "zenoh-pico/protocol/private/types.h"

/*------------------ IOSli ------------------*/
_z_iosli_t _z_iosli_wrap(uint8_t *buf, size_t capacity, size_t r_pos, size_t w_pos);
_z_iosli_t _z_iosli_make(size_t capacity);

size_t _z_iosli_readable(const _z_iosli_t *ios);
uint8_t _z_iosli_read(_z_iosli_t *ios);
void _z_iosli_read_bytes(_z_iosli_t *ios, uint8_t *dest, size_t offset, size_t length);
uint8_t _z_iosli_get(const _z_iosli_t *ios, size_t pos);

size_t _z_iosli_writable(const _z_iosli_t *ios);
void _z_iosli_write(_z_iosli_t *ios, uint8_t b);
void _z_iosli_write_bytes(_z_iosli_t *ios, const uint8_t *bs, size_t offset, size_t length);
void _z_iosli_put(_z_iosli_t *ios, uint8_t b, size_t pos);

z_bytes_t _z_iosli_to_bytes(const _z_iosli_t *ios);

void _z_iosli_clear(_z_iosli_t *ios);
void _z_iosli_free(_z_iosli_t *ios);

/*------------------ ZBuf ------------------*/
_z_zbuf_t _z_zbuf_make(size_t capacity);
_z_zbuf_t _z_zbuf_view(_z_zbuf_t *zbf, size_t length);

size_t _z_zbuf_capacity(const _z_zbuf_t *zbf);
size_t _z_zbuf_len(const _z_zbuf_t *zbf);
int _z_zbuf_can_read(const _z_zbuf_t *zbf);
size_t _z_zbuf_space_left(const _z_zbuf_t *zbf);

uint8_t _z_zbuf_read(_z_zbuf_t *zbf);
void _z_zbuf_read_bytes(_z_zbuf_t *zbf, uint8_t *dest, size_t offset, size_t length);
uint8_t _z_zbuf_get(const _z_zbuf_t *zbf, size_t pos);

size_t _z_zbuf_get_rpos(const _z_zbuf_t *zbf);
size_t _z_zbuf_get_wpos(const _z_zbuf_t *zbf);
void _z_zbuf_set_rpos(_z_zbuf_t *zbf, size_t r_pos);
void _z_zbuf_set_wpos(_z_zbuf_t *zbf, size_t w_pos);

uint8_t *_z_zbuf_get_rptr(const _z_zbuf_t *zbf);
uint8_t *_z_zbuf_get_wptr(const _z_zbuf_t *zbf);

void _z_zbuf_clear(_z_zbuf_t *zbf);
void _z_zbuf_compact(_z_zbuf_t *zbf);
void _z_zbuf_free(_z_zbuf_t *zbf);

/*------------------ WBuf ------------------*/
_z_wbuf_t _z_wbuf_make(size_t capacity, int is_expandable);

size_t _z_wbuf_capacity(const _z_wbuf_t *wbf);
size_t _z_wbuf_len(const _z_wbuf_t *wbf);
size_t _z_wbuf_space_left(const _z_wbuf_t *wbf);

int _z_wbuf_write(_z_wbuf_t *wbf, uint8_t b);
int _z_wbuf_write_bytes(_z_wbuf_t *wbf, const uint8_t *bs, size_t offset, size_t length);
void _z_wbuf_put(_z_wbuf_t *wbf, uint8_t b, size_t pos);

size_t _z_wbuf_get_rpos(const _z_wbuf_t *wbf);
size_t _z_wbuf_get_wpos(const _z_wbuf_t *wbf);
void _z_wbuf_set_rpos(_z_wbuf_t *wbf, size_t r_pos);
void _z_wbuf_set_wpos(_z_wbuf_t *wbf, size_t w_pos);

void _z_wbuf_add_iosli(_z_wbuf_t *wbf, _z_iosli_t *ios);
void _z_wbuf_add_iosli_from(_z_wbuf_t *wbf, const uint8_t *buf, size_t capacity);
_z_iosli_t *_z_wbuf_get_iosli(const _z_wbuf_t *wbf, size_t idx);
size_t _z_wbuf_len_iosli(const _z_wbuf_t *wbf);

_z_zbuf_t _z_wbuf_to_zbuf(const _z_wbuf_t *wbf);
int _z_wbuf_copy_into(_z_wbuf_t *dst, _z_wbuf_t *src, size_t length);

void _z_wbuf_clear(_z_wbuf_t *wbf);
void _z_wbuf_reset(_z_wbuf_t *wbf);
void _z_wbuf_free(_z_wbuf_t *wbf);

#endif /* _ZENOH_PICO_PROTOCOL_PRIVATE_IOBUF_H */
