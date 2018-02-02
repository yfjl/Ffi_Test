#include "stdafx.h"
#include <utility>
#include <limits.h>
#include "Ffi_Test.h"

#include <string>
using namespace std;

wchar_t * say_hello()
{
	return (wchar_t*)"Hello world你好，世界！";
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

static Listener listeners[16];
static unsigned cursor=0;

void register_listener(Listener listener) {
	if (cursor >= sizeof(listeners)/sizeof(*listeners)) {
		stringstream ss;
		ss << "最多注册"<< sizeof(listeners) / sizeof(*listeners) << "个监听器";
		throw ss.str();
	}
	listeners[cursor] = listener;
	cursor++;
}

void fire() {
	for (int i = 0; i < cursor; i++) {
		listeners[i]((char*)"张三", (char*)"12342134x");
	}
}
