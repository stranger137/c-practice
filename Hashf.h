#include <Python.h>

// ������� ������
typedef struct node {
    char *value;
    struct node *next;
} node;

// ��������� ������� � ������ ������
static PyObject* addElement(hashf *self, PyObject *args, PyObject *kwds);

// ��������� ������� � ����� ������
static PyObject* deleteElement(hashf *self, PyObject *args, PyObject *kwds);


static PyObject* findElement(hashf *self, PyObject *args, PyObject *kwds);
