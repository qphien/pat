enum rb_color { rb_red, rb_black };
struct rb_node
{
	int data;
	rb_color color;
	rb_node *left;
	rb_node *right;
	rb_node *parent;
};
class RB
{
public:
	rb_node *root = 0;
	void InsertNode(int);
	rb_node* DeleteNode(int);
	void rb_balance(rb_node*);
	void left_rotate(rb_node*);
	void right_rotate(rb_node*);
	rb_node* find_node(int);
	rb_node* TreeSuccessor(rb_node*);
	rb_node* FindMin(rb_node*);
	void DeleteFixUp(rb_node*);
	~RB() { if (root) delete root; }
};
void RB::InsertNode(int data)
{
	rb_node *x = root, *y = 0;
	bool flag;
	while (x)
	{
		y = x;
		flag = data < x->data ? 1 : 0;
		x = flag ? x->left : x->right;
	}
	x = new rb_node;
	x->data = data;
	x->left = 0;
	x->right = 0;
	x->parent = y;
	if (!y)
		root = x;
	else
	{
		if (flag)
			y->left = x;
		else
			y->right = x;
	}
	rb_balance(x);
}
void RB::rb_balance(rb_node *x)
{
	x->color = rb_red;
	while (x != root && x->parent->color == rb_red)
	{
		rb_node *y = 0;
		if (x->parent == x->parent->parent->left)
		{
			y = x->parent->parent->right;
			if (y && y->color == rb_red)
			{
				y->color = rb_black;
				x->parent->parent->color = rb_red;
				x->parent->color = rb_black;
				x = x->parent->parent;
			}
			else
			{
				if (x == x->parent->right)
				{
					x = x->parent;
					left_rotate(x);
				}
				x->parent->color = rb_black;
				x->parent->parent->color = rb_red;
				right_rotate(x->parent->parent);
			}
		}
		else
		{
			y = x->parent->parent->left;
			if (y && y->color == rb_red)
			{
				y->color = rb_black;
				x->parent->color = rb_black;
				x->parent->parent->color = rb_red;
				x = x->parent->parent;
			}
			else
			{
				if (x == x->parent->left)
				{
					x = x->parent;
					right_rotate(x);
				}
				x->parent->color = rb_black;
				x->parent->parent->color = rb_red;
				left_rotate(x->parent->parent);
			}
		}
	}
	root->color = rb_black;
}
void RB::right_rotate(rb_node *x)
{
	rb_node *y = x->left;
	x->left = y->right;
	if (y->right)
		y->right->parent = x;
	y->right = x;
	if (x->parent)
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->parent = x->parent;
	x->parent = y;
	if (x == root)
		root = y;
}
void RB::left_rotate(rb_node *x)
{
	rb_node *y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->left = x;
	if (x->parent)
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->parent = x->parent;
	x->parent = y;
	if (x == root)
		root = y;
}
rb_node* RB::find_node(int data)
{
	rb_node *x = root;
	while (x && x->data != data)
	{
		if (data < x->data)
			x = x->left;
		else
			x = x->right;
	}
	if (!x)
		return 0;
	return x;
}
rb_node* RB::FindMin(rb_node *x)
{
	while (x->left)
		x = x->left;
	return x;
}
rb_node* RB::TreeSuccessor(rb_node *x)
{
	if (x->right)
		return FindMin(x->right);
	while (x == x->parent->right)
		x = x->parent;
	x = x->parent;
	return x;
}
rb_node* RB::DeleteNode(int data)
{
	rb_node *position = find_node(data);
	rb_node *y = 0, *x = 0;
	if (!position)
	{
		cout << "Not Found" << endl;
		return 0;
	}
	if (position->left == 0 || position->right == 0)
		y = position;
	else
		y = TreeSuccessor(position);
	if (!y->left)
		x = y->right;
	else if (!y->right)
		x = y->left;
	if (!y->parent)
		root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	if (x)
		x->parent = y->parent;
	if (position != y)
	{
		position->data = y->data;
	}
	if (y->color == rb_black)
		DeleteFixUp(x);
	return y;
}
void RB::DeleteFixUp(rb_node *x)
{
	if (!x)
		return;
	while (x != root && x->color == rb_black)
	{
		rb_node *w = 0;
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->color == rb_red)
			{
				w->color = rb_black;
				x->parent->color = rb_red;
				left_rotate(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == rb_black && w->right->color == rb_black)
			{
				w->color = rb_red;
				x = x->parent;
			}
			else if (w->right->color == rb_black)
			{
				w->left->color = rb_black;
				w->color = rb_red;
				right_rotate(w);
				w = x->parent->right;
			}
			else
			{
				w->color = x->parent->color;
				x->parent->color = rb_black;
				w->right->color = rb_black;
				left_rotate(x->parent);
				x = root;
			}
		}
		else
		{
			w = x->parent->left;
			if (w->color = rb_red)
			{
				w->color = rb_black;
				x->parent->color = rb_red;
				right_rotate(x->parent);
				w = x->parent->left;
			}
			if (w->left->color == rb_black && w->right->color == rb_black)
			{
				w->color = rb_red;
				x = x->parent;
			}
			else if (w->left->color == rb_black)
			{
				w->right->color = rb_black;
				w->color = rb_red;
				left_rotate(w);
				w = x->parent->left;
			}
			else
			{
				w->color = x->parent->color;
				w->left->color = rb_black;
				x->parent->color = rb_black;
				right_rotate(x->parent);
				x = root;
			}
		}
	}
	x->color = rb_black;
}