// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>
using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

// Pointer global
Pohon *root;
Pohon *lutfiana_2311102165; // tambah variabel

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

Pohon* findNode(Pohon* node, char data) {
    if (node == NULL)
        return NULL;
    if (node->data == data)
        return node;
    Pohon* foundNode = findNode(node->left, data);
    if (foundNode == NULL)
        foundNode = findNode(node->right, data);
    return foundNode;
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Fungsi tambahan untuk menampilkan child
void displayChildren(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nChild dari node " << node->data << ":" << endl;
            if (node->left) {
                cout << "Child Kiri: " << node->left->data << endl;
            } else {
                cout << "Child Kiri: (tidak ada)" << endl;
            }
            if (node->right) {
                cout << "Child Kanan: " << node->right->data << endl;
            } else {
                cout << "Child Kanan: (tidak ada)" << endl;
            }
        }
    }
}

// Fungsi tambahan untuk menampilkan descendant
void displayDescendants(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nDescendants dari node " << node->data << ":" << endl;
            if (node->left) {
                cout << "Child Kiri: " << node->left->data << endl;
                displayDescendants(node->left);
            } else {
                cout << "Child Kiri: (tidak ada)" << endl;
            }
            if (node->right) {
                cout << "Child Kanan: " << node->right->data << endl;
                displayDescendants(node->right);
            } else {
                cout << "Child Kanan: (tidak ada)" << endl;
            }
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            deleteTree(node->left);
            deleteTree(node->right);
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            delete node;
            cout << "\nNode subtree berhasil dihapus." << endl;
        } else {
            cout << "\nNode subtree tidak ditemukan!" << endl;
        }
    }
}

// Hapus Tree
void clear() {
    if (isEmpty()) {
        cout << "\nPohon belum dibuat!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
    // Setelah menghapus pohon, pastikan root diatur ke NULL
    root = NULL;
}
// Cek Size Tree
int size(Pohon *node) {
    if (node == NULL) {
        return 0;
    } else {
        return 1 + size(node->left) + size(node->right);
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (node == NULL) {
        return 0;
    } else {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        return max(heightKiri, heightKanan) + 1;
    }
}

// Menu untuk interaksi dengan user
void menu() {
    int choice;
    char data;
    Pohon *node = NULL;

    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Tampilkan Child dari Node\n";
        cout << "8. Tampilkan Descendant dari Node\n";
        cout << "9. PreOrder Traversal\n";
        cout << "10. InOrder Traversal\n";
        cout << "11. PostOrder Traversal\n";
        cout << "12. Hapus Subtree\n";
        cout << "13. Clear Tree\n";
        cout << "14. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 
1:
                cout << "Masukkan data untuk root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data untuk node kiri: ";
                cin >> data;
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data parent node: ";
                    char parentData;
                    cin >> parentData;
                    Pohon* parentNode = findNode(root, parentData);
                    if (parentNode != NULL) {
                        insertLeft(data, parentNode);
                    } else {
                        cout << "Parent node tidak ditemukan!" << endl;
                    }
                }
                break;
            case 3:
                cout << "Masukkan data untuk node kanan: ";
                cin >> data;
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data parent node: ";
                    char parentData;
                    cin >> parentData;
                    Pohon* parentNode = findNode(root, parentData);
                    if (parentNode != NULL) {
                        insertRight(data, parentNode);
                    } else {
                        cout << "Parent node tidak ditemukan!" << endl;
                    }
                }
                break;
            case 4:
                cout << "Masukkan data node yang akan diupdate: ";
                cin >> data;
                node = findNode(root, data);
                if (node != NULL) {
                    cout << "Masukkan data baru: ";
                    char newData;
                    cin >> newData;
                    update(newData, node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 5:
                cout << "Masukkan data node yang akan di-retrieve: ";
                cin >> data;
                node = findNode(root, data);
                retrieve(node);
                break;
            case 6:
                cout << "Masukkan data node yang akan di-find: ";
                cin >> data;
                node = findNode(root, data);
                find(node);
                break;
            case 7:
                cout << "Masukkan data node yang akan ditampilkan child-nya: ";
                cin >> data;
                node = findNode(root, data);
                displayChildren(node);
                break;
            case 8:
                cout << "Masukkan data node yang akan ditampilkan descendant-nya: ";
                cin >> data;
                node = findNode(root, data);
                displayDescendants(node);
                break;
            case 9:
                cout << "\nPreOrder Traversal:\n";
                preOrder(root);
                cout << "\n";
                break;
            case 10:
                cout << "\nInOrder Traversal:\n";
                inOrder(root);
                cout << "\n";
                break;
            case 11:
                cout << "\nPostOrder Traversal:\n";
                postOrder(root);
                cout << "\n";
                break;
            case 12:
                cout << "Masukkan data node yang subtreenya akan dihapus: ";
                cin >> data;
                node = findNode(root, data);
                if (node != NULL) {
                    deleteSub(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 13:
                clear();
                break;
            case 14:
                cout << "Keluar...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 15);
}

int main() {
    init();
    menu();
    return 0;
}
