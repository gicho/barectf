#ifndef _BARECTF_H
#define _BARECTF_H

/*
 * The following C code was generated by barectf 2.1.0-dev
 * on 2016-03-15T21:29:16.069818.
 *
 * For more details, see <https://github.com/efficios/barectf>.
 */

#include <stdint.h>

#include "barectf-bitfield.h"

struct barectf_ctx;

uint32_t barectf_packet_size(void *ctx);
int barectf_packet_is_full(void *ctx);
int barectf_packet_is_empty(void *ctx);
uint32_t barectf_packet_events_discarded(void *ctx);
uint8_t *barectf_packet_buf(void *ctx);
void barectf_packet_set_buf(void *ctx, uint8_t *buf, uint32_t buf_size);
uint32_t barectf_packet_buf_size(void *ctx);
int barectf_packet_is_open(void *ctx);

/* barectf platform callbacks */
struct barectf_platform_callbacks {
	/* clock callbacks */
	uint64_t (*default_clock_get_value)(void *);

	/* is back-end full? */
	int (*is_backend_full)(void *);

	/* open packet */
	void (*open_packet)(void *);

	/* close packet */
	void (*close_packet)(void *);
};

/* common barectf context */
struct barectf_ctx {
	/* platform callbacks */
	struct barectf_platform_callbacks cbs;

	/* platform data (passed to callbacks) */
	void *data;

	/* output buffer (will contain a CTF binary packet) */
	uint8_t *buf;

	/* packet size in bits */
	uint32_t packet_size;

	/* content size in bits */
	uint32_t content_size;

	/* current position from beginning of packet in bits */
	uint32_t at;

	/* packet header + context size (content offset) */
	uint32_t off_content;

	/* events discarded */
	uint32_t events_discarded;

	/* current packet is opened */
	int packet_is_open;
};

/* context for stream "default" */
struct barectf_default_ctx {
	/* parent */
	struct barectf_ctx parent;

	/* config-specific members follow */
	uint32_t off_tph_magic;
	uint32_t off_tph_uuid;
	uint32_t off_tph_stream_id;
	uint32_t off_spc_timestamp_begin;
	uint32_t off_spc_timestamp_end;
	uint32_t off_spc_packet_size;
	uint32_t off_spc_content_size;
	uint32_t off_spc_events_discarded;
};

/* initialize context */
void barectf_init(
	void *ctx,
	uint8_t *buf,
	uint32_t buf_size,
	struct barectf_platform_callbacks cbs,
	void *data
);

/* open packet for stream "default" */
void barectf_default_open_packet(
	struct barectf_default_ctx *ctx
);

/* close packet for stream "default" */
void barectf_default_close_packet(struct barectf_default_ctx *ctx);

/* trace (stream "default", event "simple_uint32") */
void barectf_default_trace_simple_uint32(
	struct barectf_default_ctx *ctx,
	uint32_t ep_value
);

/* trace (stream "default", event "simple_int16") */
void barectf_default_trace_simple_int16(
	struct barectf_default_ctx *ctx,
	int16_t ep_value
);

/* trace (stream "default", event "simple_float") */
void barectf_default_trace_simple_float(
	struct barectf_default_ctx *ctx,
	float ep_value
);

/* trace (stream "default", event "simple_string") */
void barectf_default_trace_simple_string(
	struct barectf_default_ctx *ctx,
	const char * ep_value
);

/* trace (stream "default", event "simple_enum") */
void barectf_default_trace_simple_enum(
	struct barectf_default_ctx *ctx,
	uint8_t ep_value
);

/* trace (stream "default", event "a_few_fields") */
void barectf_default_trace_a_few_fields(
	struct barectf_default_ctx *ctx,
	int32_t ep_int32,
	uint16_t ep_uint16,
	double ep_dbl,
	const char * ep_str,
	uint8_t ep_state
);

/* trace (stream "default", event "bit_packed_integers") */
void barectf_default_trace_bit_packed_integers(
	struct barectf_default_ctx *ctx,
	uint8_t ep_uint1,
	int8_t ep_int1,
	uint8_t ep_uint2,
	int8_t ep_int3,
	uint8_t ep_uint4,
	int8_t ep_int5,
	uint8_t ep_uint6,
	int8_t ep_int7,
	uint8_t ep_uint8
);

#endif /* _BARECTF_H */