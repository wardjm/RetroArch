/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2013 - Hans-Kristian Arntzen
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CORE_INFO_H_
#define CORE_INFO_H_

#include "conf/config_file.h"
#include "file.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
   char *path;
   config_file_t *data;
   char *display_name;
   char *supported_extensions;
   struct string_list *supported_extensions_list;
} core_info_t;

typedef struct {
   core_info_t *list;
   size_t count;
   char *all_ext;
} core_info_list_t;

core_info_list_t *core_info_list_new(const char *modules_path);
void core_info_list_free(core_info_list_t *core_info_list);

bool core_info_does_support_file(const core_info_t *core, const char *path);

// Non-reentrant, does not allocate. Returns pointer to internal state.
void core_info_list_get_supported_cores(core_info_list_t *core_info_list, const char *path,
      const core_info_t **infos, size_t *num_infos);

const char *core_info_list_get_all_extensions(core_info_list_t *core_info_list);

#ifdef __cplusplus
}
#endif

#endif /* CORE_INFO_H_ */
