#include <stdio.h>
#include <glib.h>

gboolean callback1(gpointer data)
{
  printf("callback1\n");
  
  return TRUE;
}

gboolean callback2(gpointer data)
{
  printf("callback2\n");
  
  return TRUE;
}

gboolean callback3(gpointer data)
{
  printf("callback3\n");
  
  return TRUE;
}

int main(int argc, const char* argv[])
{
	GMainLoop* loop1 = NULL;
	loop1 = g_main_loop_new (NULL, FALSE);
	g_timeout_add_seconds(1, callback1, NULL);
	g_timeout_add_seconds(3, callback2,NULL);
	g_timeout_add_seconds(5, callback3,NULL);
	
	g_main_loop_run(loop1);
	g_free(loop1);
	return 0;
}

//https://www.cs.tut.fi/lintula/manual/gtk/glib/glib-threads.html
//https://www.cs.tut.fi/lintula/manual/gtk/glib/glib-memory-chunks.html
//g++ main.cpp  `pkg-config --cflags glib-2.0`  `pkg-config --libs glib-2.0`