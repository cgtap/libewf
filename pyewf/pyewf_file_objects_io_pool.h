/*
 * Python file objects IO pool functions
 *
 * Copyright (C) 2008-2018, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _PYEWF_FILE_OBJECTS_IO_POOL_H )
#define _PYEWF_FILE_OBJECTS_IO_POOL_H

#include <common.h>
#include <types.h>

#include "pyewf_libbfio.h"
#include "pyewf_libcerror.h"
#include "pyewf_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

int pyewf_file_objects_pool_initialize(
     libbfio_pool_t **pool,
     PyObject *sequence_object,
     int access_flags,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYEWF_FILE_OBJECTS_IO_POOL_H ) */

