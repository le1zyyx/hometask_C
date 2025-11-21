#include "listutils.h"
#include <stdio.h>

int main(void) {
    c_list* list = create_list(2);
    append_list(list, "d", -6);
    append_list(list, "f", 0.1f);
    append_list(list, "s", "hello");
    print_list(list);
    print_element(list, 0);
    print_element(list, 1);
    print_element(list, 2);

    dump_list_to_file(list, "list.txt");
    c_list* loaded = create_list_from_file("list.txt");
    print_list(loaded);

    destroy_list(list);
    destroy_list(loaded);
    return 0;
}
