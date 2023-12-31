/*
 * Copyright © 2022 Isabella Basso do Amaral <isabbasso@riseup.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef IGT_KTAP_H
#define IGT_KTAP_H

#define BUF_LEN 4096

#include <pthread.h>

void *igt_ktap_parser(void *unused);

typedef struct ktap_test_results_element {
	char test_name[BUF_LEN + 1];
	bool passed;
	struct ktap_test_results_element *next;
} ktap_test_results_element;

struct ktap_test_results {
	ktap_test_results_element *head;
	pthread_mutex_t mutex;
	bool still_running;
};



struct ktap_test_results *ktap_parser_start(FILE *fp, bool is_builtin);
int ktap_parser_stop(void);

#endif /* IGT_KTAP_H */
