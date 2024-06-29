#include<iostream>
using namespace std;

// Struktur Node BST dalam bentuk struct dan pointer
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Fungsi Pembentukan BST
struct Node *CreateNode(int value) {
    struct Node *NewNode = new Node();
    NewNode->data = value;
    NewNode->left = nullptr;
    NewNode->right = nullptr;
    return NewNode;
}

// Fungsi Memasukkan Value
struct Node *Insert(struct Node *root, int value) {
    if (root == nullptr) {
        return CreateNode(value);
    }
    if (value < root->data) {
        root->left = Insert(root->left, value);
    } else if (value > root->data) {
        root->right = Insert(root->right, value);
    }
    return root;
}

// Fungsi Predecessor
struct Node *Predecessor(struct Node *root) {
    struct Node *curr = root->left;
    while(curr->right != nullptr) {
        curr = curr->right;
    }
    return curr;
}

// Fungsi Delete
struct Node *DeleteNode(struct Node *root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->data) {
        root->left = DeleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = DeleteNode(root->right, value);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            struct Node *temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            struct Node *temp = Predecessor(root);
            root->data = temp->data;
            root->left = DeleteNode(root->left, temp->data);
        }
    }
    return root;
}

// Fungsi Delete semua node
struct Node *RemoveAll(struct Node *root) {
    if (root == nullptr) {
        return nullptr;
    }
    root->left = RemoveAll(root->left);
    root->right = RemoveAll(root->right);
    delete root;
    return nullptr;
}

// Fungsi Search untuk melakukan pencarian
struct Node *SearchNode(Node *root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return SearchNode(root->left, value);
    } else {
        return SearchNode(root->right, value);
    }
}

// Teknik InOrder
void InorderTraversal(Node *root) {
    if (root == nullptr)
        return;
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

// Teknik PreOrder
void PreOrderTraversal(Node *root) {
    if (root) {
        cout << root->data << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

// Teknik PostOrder
void PostOrderTraversal(Node *root) {
    if (root) {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main () {
    struct Node *root = nullptr;
    int jumlah_node_sekarang = 0;

    cout << "========================================== Tugas Akhir SDA Binary Search Tree ==========================================";
    cout << "\n\n";

    while (true) {
        int menu;
        cout << "Silahkan pilih menu yang telah kami sediakan. \n";
        cout << " 1. Membentuk Binary Search Tree \n";
        cout << " 2. Menambah Node \n";
        cout << " 3. Mencari Data Node \n";
        cout << " 4. Menghapus Data Node \n";
        cout << " 5. Menghapus Binary Search Tree \n";
        cout << " 6. Print Binary Search Tree \n";
        cout << " 7. Keluar Program \n\n";
        cout << "Menu: ";
        cin >> menu;

        switch(menu) {
            case 1: {
                if (root == nullptr) {
                    int jml_node;
                    cout << " Attention: Jangan Menginput Data Node Dengan Nilai Yang Sama";
                    cout << "\n\n";
                    cout << " Masukkan jumlah node untuk Binary Search Tree: ";
                    cin >> jml_node;

                    for(int i = 0; i < jml_node; i++) {
                        if (i == 0) {
                            int root_node;
                            cout << " Masukkan root node: ";
                            cin >> root_node;
                            root = Insert(root, root_node);
                        } else {
                            int child_node;
                            cout << " Masukkan child node: ";
                            cin >> child_node;
                            Insert(root, child_node);
                        }
                        jumlah_node_sekarang++;
                    }
                    cout << "\n";
                } else {
                    cout << " Binary Search Tree Telah Terbentuk";
                    cout << "\n\n";
                }
                break;
            }
            case 2: {
                if (root != nullptr) {
                    int tambah_node;
                    cout << " Jumlah node saat ini: " << jumlah_node_sekarang << "\n\n";
                    cout << " Data Node Binary Search Tree \n => ";
                    InorderTraversal(root);
                    cout << "\n\n";

                    cout << " Attention: Jangan Menginput Data Node Sama Dengan Data Node Yang Sudah Terbentuk";
                    cout << "\n\n";
                    cout << " Masukkan jumlah node yang ingin di tambahkan: ";
                    cin >> tambah_node;

                    for(int i = 0; i < tambah_node; i++) {
                        int tambah_data_node;
                        cout << " Masukkan data node ke " << i + 1 << ": ";
                        cin >> tambah_data_node;
                        Insert(root, tambah_data_node);
                        jumlah_node_sekarang++;
                    }
                    cout << "\n";
                } else {
                    cout << " Binary Search Tree Belum Terbentuk";
                    cout << "\n\n";
                }
                break;
            }
            case 3: {
                if(root == nullptr) {
                    cout << " Binary Search Tree Belum Terbentuk";
                    cout << "\n\n";
                } else {
                    cout << " Data Node Binary Search Tree \n => ";
                    InorderTraversal(root);
                    cout << "\n\n";
                    int Cari_Nilai_Node;
                    cout << " Masukkan Data Node Yang Ingin Di Cari: ";
                    cin >> Cari_Nilai_Node;
                    struct Node *Hasil_Pencarian_Nilai = SearchNode(root, Cari_Nilai_Node);
                    if (Hasil_Pencarian_Nilai) {
                        cout << " Data " << Cari_Nilai_Node << " ditemukan dalam Binary Search Tree " << endl;
                    } else {
                        cout << " Data " << Cari_Nilai_Node << " tidak ditemukan dalam Binary Search Tree \n" << endl;
                    }
                    cout << "\n\n";
                }
                break;
            }
            case 4: {
                if(root == nullptr) {
                    cout << " Binary Search Tree Belum Terbentuk";
                    cout << "\n\n";
                } else {
                    int hapus;
                    cout << " Data Node Binary Search Tree \n => ";
                    InorderTraversal(root);
                    cout << "\n\n";
                    cout << " Masukkan data yang ingin di hapus: ";
                    cin >> hapus;
                    struct Node *Cek_Data = SearchNode(root, hapus);
                    if(Cek_Data) {
                        DeleteNode(root, hapus);
                        jumlah_node_sekarang--;
                        cout << " Data " << hapus << " Telah Terhapus, Silahkan Cek Kembali";
                        cout << "\n\n";
                        if (jumlah_node_sekarang == 0) {
                            root = nullptr;
                        }
                        cout << "\n";
                    } else {
                        cout << " Data " << hapus << " tidak ditemukan dalam Binary Search Tree \n" << endl;
                    }
                }
                break;
            }
            case 5: {
                if(root == nullptr) {
                    cout << " Binary Search Tree Belum Terbentuk";
                    cout << "\n\n";
                } else {
                    RemoveAll(root);
                    jumlah_node_sekarang = 0;
                    root = nullptr;
                    cout << " Binary Search Tree Telah Di Hapus";
                    cout << "\n\n";
                }
                break;
            }
            case 6: {
                if(root == nullptr) {
                    cout << " Binary Search Tree Belum Terbentuk";
                    cout << "\n\n";
                } else {
                    int pilih_teknik;
                    cout << " Pilih salah satu teknik traversal untuk pengurutan. \n";
                    cout << " 1. Teknik InOrder Traversal \n";
                    cout << " 2. Teknik PreOrder Traversal \n";
                    cout << " 3. Teknik PostOrder Traversal \n\n";
                    cout << " Pilih: ";
                    cin >> pilih_teknik;

                    switch(pilih_teknik) {
                        case 1:
                            cout << "\n";
                            cout << " Data Node Binary Search Tree Secara InOrder \n => ";
                            InorderTraversal(root);
                            break;
                        case 2:
                            cout << "\n";
                            cout << " Data Node Binary Search Tree Secara PreOrder \n => ";
                            PreOrderTraversal(root);
                            break;
                        case 3:
                            cout << "\n";
                            cout << " Data Node Binary Search Tree Secara PostOrder \n => ";
                            PostOrderTraversal(root);
                            break;
                        default:
                            cout << " Pilihan tidak tersedia, mohon pilih teknik yang telah di sediakan... ";
                            cout << "\n\n";
                            break;
                    }
                    cout << "\n\n";
                }
                break;
            }
            case 7:
                cout << "\n Terima Kasih Telah Mencoba Program Ini\n\n";
                cout << "\t  Program di tutup\n";
                return 0;
            default:
                cout << " Pilihan tidak tersedia, mohon pilih menu yang telah di sediakan... ";
                cout << "\n\n";
                break;
        }
    }
}
