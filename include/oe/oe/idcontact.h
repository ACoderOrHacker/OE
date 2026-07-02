/**
 * @file idcontact.h
 * @brief The OE ID contact macro.
 * This macro is used to concatenate two tokens into a single token.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#define OE_INTERNAL_ID_CONTACT(x, y) x##y

/**
 * @define OE_ID_CONTACT
 * @brief The OE ID contact macro.
 * This macro is used to concatenate two tokens into a single token.
 * @param a The first token.
 * @param b The second token.
 * @return The concatenated token.
 */
#define OE_ID_CONTACT(a, b) OE_INTERNAL_ID_CONTACT(a, b)
