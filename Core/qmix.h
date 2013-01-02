/////////////////////////////////////////////////////////////////////////////
//
// qmix - QSound mixer
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __Q_QMIX_H__
#define __Q_QMIX_H__

#include "emuconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

sint32 EMU_CALL qmix_init(void);
uint32 EMU_CALL qmix_get_state_size(void);
void   EMU_CALL qmix_clear_state(void *state);

void   EMU_CALL qmix_set_sample_rate(void *state, uint32 rate);
void   EMU_CALL qmix_set_sample_rom(void *state, void *rom, uint32 size);
void   EMU_CALL qmix_command(void *state, uint8 cmd, uint16 data);
void   EMU_CALL qmix_render(void *state, sint16 *buf, uint32 samples);

typedef void (EMU_CALL *qmix_advance_callback)(void *context, uint32 samples);
void   EMU_CALL qmix_set_advance_callback(void *state, qmix_advance_callback cb, void *context);

typedef void (EMU_CALL *qmix_command_callback)(void *context, uint8 cmd, uint16 data);
void   EMU_CALL qmix_set_command_callback(void *state, qmix_command_callback cb, void *context);

typedef void (EMU_CALL *qmix_sample_usage_callback)(void *context, uint32 offset, uint32 size);
void   EMU_CALL qmix_set_sample_usage_callback(void *state, qmix_sample_usage_callback cb, void *context);

#ifdef __cplusplus
}
#endif

#endif
