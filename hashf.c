#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Hashf.h>

const int k = 53;
const int p = 7;
int mass[p];

int hashFunction(char s[]) {
    int n = strlen(s);
    int i, curNum;
    int ans = 0;
    int curPower = 1;
    char c;
    for(i = 0; i < n; i++) {
        c = s[i];
        curNum = (int)(c - "a" + 1);
        curPower = (curPower * k) % p;
        ans = (ans + curNum * curPower) % p;
    }
    return ans;
}


typedef struct node {
    char *value;
    struct node *next;
} node;


static PyObject* addElement(linked_list *self, PyObject *args, PyObject *kwds)/*(char *value)*/ {
    char value;
    if(!PyArg_ParseTuple(args, "s", &value))
        return NULL;
    hash = hashFunction(value);
    node *head = mass[hash];

    node *newNode, *cur;
    newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
    Py_INCREF(Py_None);
    return Py_None;;
}

static PyObject* deleteElement(linked_list *self, PyObject *args, PyObject *kwds)/*(char *value)*/ {
    char value;
    if(!PyArg_ParseTuple(args, "s", &value))
        return NULL;
    hash = hashFunction(value);
    node *head = mass[hash];

    if (head == NULL) {
        Py_INCREF(Py_None);
        return Py_None;
    } else if (head->value == value) {
        free(head);
        Py_INCREF(Py_None);
        return Py_None;
    } else {
        node *cur, *prevCur = NULL;
        cur = head;
        while (cur->next != NULL && cur->value != value) {
            prevCur = cur;
            cur = cur->next;
        }
        if(cur->value == value) {
            prevCur->next = cur->next;
            free(cur);
            Py_INCREF(Py_None);
            return Py_None;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(Py_None);
    return Py_None;;
}


static PyObject* findElement(linked_list *self, PyObject *args, PyObject *kwds)/*(char *value)*/ {
    char value;
    if(!PyArg_ParseTuple(args, "s", &value))
        return NULL;
    hash = hashFunction(value);
    node *head = mass[hash];

    if (head ==  NULL){
        return 0;
    }
    node *cur;
    cur = head;
    while (strcmp(cur->value, value) != 0) {
        if (cur->next == NULL) {
            return 0;
        }
        cur = cur->next;
    }
    return Py_BuildValue("s", hash);

    }
    static PyMethodDef hashf_methods[] = {
        {"addElement", (PyCFunction)addElement, METH_NOARGS,
        PyDoc_STR("add element to the hash table")},
        {"deleteElement", (PyCFunction)deleteElement, METH_NOARGS,
        PyDoc_STR("delete element from the hash table")},
        {"findElement", (PyCFunction)findElement, METH_VARARGS,
        PyDoc_STR("find element hash in hash table")},
        {NULL, NULL},
    };

static PyTypeObject hashf_Type = {
 /* Everything about object */
 PyVarObject_HEAD_INIT(NULL, 0)
 "hashf",         	/* tp_name */
  sizeof(node), /* tp_basicsize */
    0,                   	/* tp_itemsize */
    0,                   	/* tp_dealloc */
    0,                   	/* tp_print */
    0,                   	/* tp_getattr */
    0,                   	/* tp_setattr */
    0,                   	/* tp_reserved */
    0,                   	/* tp_repr */
    0,                   	/* tp_as_number */
    0,                	   /* tp_as_sequence */
    0,                   	/* tp_as_mapping */
    0,                   	/* tp_hash */
    0,                   	/* tp_call */
    0,                   	/* tp_str */
    0,                   	/* tp_getattro */
    0,                       /* tp_setattro */
    0,                   	/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,    	/* tp_flags */
    "hash list of objects",       	/* tp_doc: test.Test.__doc__ */
    0,                   	/* tp_traverse */
    0,                       /* tp_clear */
    0,                   	/* tp_richcompare */
    0,                   	/* tp_weaklistoffset */
    0,                   	/* tp_iter */
    0,                   	/* tp_iternext */
    hashf_methods,     	 /* tp_methods */
    0,                   	/* tp_members */
    0,                   	/* tp_getset */
    0,                   	/* tp_base */
    0,                   	/* tp_dict */
    0,                   	/* tp_descr_get */
    0,                   	/* tp_descr_set */
    0,                   	/* tp_dictoffset */
    0,   /* tp_init */
    0,                   	/* tp_alloc */
    0,                   	/* tp_new */
};
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT, // îáÿçàòåëüíûé ìàêðîñ
    "hash table",               // my_plus.__name__
    "table of hashes", // my_plus.__doc__
    -1,
    NULL,
    NULL,
    NULL           // ñþäà ïåðåäàåì ìàññèâ ñ ìåòîäàìè ìîäóëÿ
};

PyMODINIT_FUNC PyInit_hashf(void)
{
    PyObject* m;

    hashf_Type.tp_new = PyType_GenericNew;
    if(PyType_Ready(&hashf_Type) < 0)
            return NULL;

    m = PyModule_Create(&linked_list_module);
    if(m == NULL)
            return NULL;

    Py_INCREF(&hashf_Type);
    // x=Linked_List.Create() - òàê ñîçäàåòñÿ îáúåêò õ êëàññà Linked_List
    PyModule_AddObject(m, "Create", (PyObject *)&hashf_Type);

    return m;
}
