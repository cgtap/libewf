/*
 * Values table functions
 *
 * Copyright (c) 2006-2008, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBEWF_VALUES_TABLE_H )
#define _LIBEWF_VALUES_TABLE_H

#include <common.h>
#include <narrow_string.h>
#include <types.h>
#include <wide_string.h>

#include "libewf_string.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libewf_values_table libewf_values_table_t;

struct libewf_values_table
{
	/* The amount of values
	 */
	int amount_of_values;

	/* The value identifiers
	 */
	libewf_character_t **identifier;

	/* The value identifier lengths
	 */
	size_t *identifier_length;

	/* The values
	 */
	libewf_character_t **value;

	/* The value lengths
	 */
	size_t *value_length;
};

int libewf_values_table_initialize(
     libewf_values_table_t **values_table,
     int amount_of_values,
     libewf_error_t **error );

int libewf_values_table_free(
     libewf_values_table_t **values_table,
     libewf_error_t **error );

int libewf_values_table_resize(
     libewf_values_table_t *values_table,
     int amount_of_values,
     libewf_error_t **error );

int libewf_values_table_get_index(
     libewf_values_table_t *values_table,
     const char *identifier,
     size_t identifier_length,
     int *index,
     libewf_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )
int libewf_values_table_get_index_wide(
     libewf_values_table_t *values_table,
     const wchar_t *identifier,
     size_t identifier_length,
     int *index,
     libewf_error_t **error );
#endif

int libewf_values_table_get_identifier(
     libewf_values_table_t *values_table,
     int index,
     char *identifier,
     size_t identifier_size,
     libewf_error_t **error );

int libewf_values_table_set_identifier(
     libewf_values_table_t *values_table,
     int index,
     const char *identifier,
     size_t indentifier_length,
     libewf_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )
int libewf_values_table_get_identifier_wide(
     libewf_values_table_t *values_table,
     int index,
     wchar_t *identifier,
     size_t identifier_size,
     libewf_error_t **error );

int libewf_values_table_set_identifier_wide(
     libewf_values_table_t *values_table,
     int index,
     const wchar_t *identifier,
     size_t indentifier_length,
     libewf_error_t **error );
#endif


#if defined( HAVE_WIDE_CHARACTER_TYPE )
#define libewf_values_table_get_identifier_libewf_string( values_table, index, identifier, identifier_size, error ) \
	libewf_values_table_get_identifier_wide( values_table, index, identifier, identifier_size, error )

#define libewf_values_table_set_identifier_libewf_string( values_table, index, identifier, indentifier_length, error ) \
	libewf_values_table_set_identifier_wide( values_table, index, identifier, indentifier_length, error )

#else
#define libewf_values_table_get_identifier_libewf_string( values_table, index, identifier, identifier_size, error ) \
	libewf_values_table_get_identifier( values_table, index, identifier, identifier_size, error )

#define libewf_values_table_set_identifier_libewf_string( values_table, index, identifier, indentifier_length, error ) \
	libewf_values_table_set_identifier( values_table, index, identifier, indentifier_length, error )
#endif

int libewf_values_table_get_value(
     libewf_values_table_t *values_table,
     const char *identifier,
     size_t identifier_length,
     char *value,
     size_t value_size,
     libewf_error_t **error );

int libewf_values_table_set_value(
     libewf_values_table_t *values_table,
     const char *identifier,
     size_t identifier_length,
     const char *value,
     size_t value_length,
     libewf_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )
int libewf_values_table_get_value_wide(
     libewf_values_table_t *values_table,
     const wchar_t *identifier,
     size_t identifier_length,
     wchar_t *value,
     size_t value_size,
     libewf_error_t **error );

int libewf_values_table_set_value_wide(
     libewf_values_table_t *values_table,
     const wchar_t *identifier,
     size_t identifier_length,
     const wchar_t *value,
     size_t value_length,
     libewf_error_t **error );
#endif

#if defined( HAVE_WIDE_CHARACTER_TYPE )
#define libewf_values_table_get_value_libewf_string( values_table, identifier, identifier_length, value, value_size, error ) \
	libewf_values_table_get_value_wide( values_table, identifier, identifier_length, value, value_size, error )

#define libewf_values_table_set_value_libewf_string( values_table, identifier, identifier_length, value, value_length, error ) \
	libewf_values_table_set_value_wide( values_table, identifier, identifier_length, value, value_length, error )

#else
#define libewf_values_table_get_value_libewf_string( values_table, identifier, identifier_length, value, value_size, error ) \
	libewf_values_table_get_value( values_table, identifier, identifier_length, value, value_size, error )

#define libewf_values_table_set_value_libewf_string( values_table, identifier, identifier_length, value, value_length, error ) \
	libewf_values_table_set_value( values_table, identifier, identifier_length, value, value_length, error )

#endif

#if defined( __cplusplus )
}
#endif

#endif

