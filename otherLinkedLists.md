# Linked List
Svantaggi:
- Necessità del nodo precedente;
- Aggiornamento della testa;


# Altre implementazioni
- Liste doppiamente collegate;
- Liste circolari (con nodo fittizio);

## Liste doppiamente collegate
    ATTENZIONE! Non risolvono al meglio il problema del nodo precedente!

    struct DoubleListNode {
        struct Data *data;
        struct DoubleListNode *prev;
        struct DoubleListNode *next;
    }

    // createNode(Data *d);

    struct DoubleListNode *insInOrdine(struct DoubleListNode *head, Data *d) {
        struct DoubleListNode *curr = head;
        struct DoubleListNode *prev = head;

        struct DoubleListNode *node = NULL;

        if (head == NULL) {
            head = createNode(d);
        }
        else {
            while (curr != NULL && (d->val > curr->data->val)) {
                prev = curr;
                curr = curr->next;
            }

            tmp = createNode(d);

            if (prev == curr) {
                tmp->next = head;
                head->prev = tmp;
            }
            else {
                tmp->next = curr;
                tmp->prev = prev;

                prev->next = tmp;

                if (curr != NULL) {
                    curr->prev = tmp:
                }
            }
        }

        return head;
    }

## Liste circolari (con nodo fittizio)
    struct DoubleListNode {
        // TODO copy the upper struct;
    };

    struct DoubleListNode *createList() {
        struct DoubleListNode *tmp = (struct) malloc(); // TODO

        tmp->next = tmp;
        tmp->prev = tmp;

        return tmp;
    }

    int main(void) {
        struct DoubleListNode *head;
    }
