#include <Python.h>

// элемент списка
typedef struct node {
    char *value;
    struct node *next;
} node;

// добавляет элемент в начало списка
static PyObject* addElement(hashf *self, PyObject *args, PyObject *kwds);

// добавляет элемент в конец списка
static PyObject* deleteElement(hashf *self, PyObject *args, PyObject *kwds);


static PyObject* findElement(hashf *self, PyObject *args, PyObject *kwds);
