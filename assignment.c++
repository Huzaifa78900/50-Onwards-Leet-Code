
int treeHeight(const BinaryNode* node) {
    if (!node) return 0;
    return 1 + max(treeHeight(node->left.get()), treeHeight(node->right.get()));
}

// A compact sideways view: right subtree appears above the parent.
void displayBinaryTree(const BinaryNode* node, int depth = 0,
                       const string& branch = "ROOT: ") {
    if (!node) return;
    displayBinaryTree(node->right.get(), depth + 1, "R--- ");
    cout << string(depth * 6, ' ') << branch << node->name << '\n';
    displayBinaryTree(node->left.get(), depth + 1, "L--- ");
}

int main() {
    cout << "====================================================\n";
    cout << "       BAHRIA UNIVERSITY | TREE MANAGEMENT\n";
    cout << "====================================================\n\n";

    // General tree: an example structure, then an interactive add-child option.
    auto university = make_unique<GeneralNode>("Bahria University");
    addChild(university.get(), "Computer Science");
    addChild(university.get(), "Electrical Engineering");
    addChild(university.get(), "Management Sciences");

    GeneralNode* cs = findGeneralNode(university.get(), "Computer Science");
    addChild(cs, "Artificial Intelligence");
    addChild(cs, "Software Engineering");
    addChild(findGeneralNode(university.get(), "Electrical Engineering"), "Power Systems");
    addChild(findGeneralNode(university.get(), "Management Sciences"), "Finance");

    cout << "TASK 1 — GENERAL TREE (PREORDER)\n";
    printGeneralPreorder(university.get());

    char addMore;
    cout << "\nAdd another sub-department? (y/n): ";
    cin >> addMore;
    while (addMore == 'y' || addMore == 'Y') {
        string parentName, childName;
        cout << "Parent department (use underscores for spaces): ";
        cin >> parentName;
        cout << "New child name (use underscores for spaces): ";
        cin >> childName;

        GeneralNode* parent = findGeneralNode(university.get(), parentName);
        if (parent) {
            addChild(parent, childName);
            cout << "Department added successfully.\n";
        } else {
            cout << "Parent not found. No change made.\n";
        }
        cout << "Add one more? (y/n): ";
        cin >> addMore;
    }

    cout << "\nUpdated general-tree structure:\n";
    printGeneralPreorder(university.get());

    // Binary tree: the user supplies employee names in level-order.
    cout << "\nTASK 2 — BINARY TREE CREATION\n";
    cout << "Enter employee names in level order; use # for an empty child.\n";
    cout << "Example: Manager_A Employee_B Employee_C # Employee_E # #\n";
    cout << "Number of tokens: ";
    int count;
    cin >> count;

    if (count <= 0) {
        cout << "No employee nodes supplied. Exiting safely.\n";
        return 0;
    }

    vector<string> values(count);
    cout << "Enter " << count << " token(s): ";
    for (string& value : values) cin >> value;

    auto employees = buildBinaryTree(values);
    if (!employees) {
        cout << "The binary tree is empty.\n";
        return 0;
    }

    cout << "\nBinary-tree view (right side is shown above):\n";
    displayBinaryTree(employees.get());

    cout << "\nPreorder : "; preorder(employees.get());
    cout << "\nInorder  : "; inorder(employees.get());
    cout << "\nPostorder: "; postorder(employees.get());
    cout << "\n\nTree depth (height in levels): " << treeHeight(employees.get()) << '\n';

    // Task 3: search and report the complete root-to-employee chain.
    cout << "\nTASK 3 — EMPLOYEE SEARCH\n";
    cout << "Employee name to search (use underscores for spaces): ";
    string target;
    cin >> target;

    vector<string> chain;
    if (findEmployee(employees.get(), target, chain)) {
        cout << target << " found. Reporting chain: ";
        for (size_t i = 0; i < chain.size(); ++i) {
            if (i) cout << " -> ";
            cout << chain[i];
        }
        cout << '\n';
    } else {
        cout << target << " was not found in the hierarchy.\n";
    }

    cout << "\nProgram completed. Thank you!\n";
    return 0;
}
