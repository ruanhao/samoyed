void PostOrder(BTNode *node)
{
    LinkedList list = LL_init();
    BTNode *tmp;
    while (node != NULL || !LL_isEmpty(list)) {
        if (node != NULL) {
            LL_push(list, node);
            node = node->left;
        } else {
            tmp = (BTNode *)LL_pop(list);
            if (tmp->first == 0) { // first time
                tmp->first = 1;
                LL_push(list, tmp);
                node = tmp->right;
            } else {
                H_DEBUG_MSG("%s", tmp->data);
                node = NULL;
            }
        }
    }
}

void PreOrder(BTNode *node)
{
    LinkedList list = LL_init();
    while (node != NULL || !LL_isEmpty(list)) {
        if (node != NULL) {
            H_DEBUG_MSG("%s", node->data);
            LL_push(list, node);
            node = node->left;
        } else {
            node = ((BTNode *)LL_pop(list))->right;
        }
    }
}

void InOrder(BTNode *node)
{
    LinkedList list = LL_init();
    while (node != NULL || !LL_isEmpty(list)) {
        if (node != NULL) {
            LL_push(list, node);
            node = node->left;
        } else {
            node = (BTNode *)LL_pop(list);
            H_DEBUG_MSG("%s", node->data);
            node = node->right;
        }
    }
}
