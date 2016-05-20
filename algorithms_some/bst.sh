#!/bin/bash
#
# Binary search tree is of the form:
#               10
#              /  \
#             /    \
#            4      16
#           / \    /  
#          1   7  12
#

# Print the binary search tree by doing a recursive call on each node.
# Call the left node, print the value of the current node, call the right node.
# Cost is O(N), where N is the number of elements in the tree, as we have to
# visit each node once.
print_binary_search_tree() {
	local node="$*";
	# Test is the node id is blank, if so return
	if [ "${node}xxx" == "xxx" ]; then
		return;
	fi
	print_binary_search_tree $(eval ${node}.getLeftChild)
	echo $(${node}.getValue)
	print_binary_search_tree $(eval ${node}.getRightChild)
}

### Utility functions to generate a BST ###

# Define set 'methods'
set_node_left() {
	eval "${1}.getLeftChild()  { echo "$2"; }"
}
set_node_right() {
	eval "${1}.getRightChild() { echo "$2"; }"
}
set_node_value() {
	eval "${1}.getValue()      { echo "$2"; }"
}

# Generate unique id:
gen_uid() {
	# prefix 'id' to the uid generated to guarentee
	# it starts with chars, and hence will work as a
	# bash variable
	echo "id$(uuidgen|tr -d '-')";
}

# Generates a new node 'object'
new_node() {
	local node_id="$1";
	local value="$2";
	local left="$3";
	local right="$4";
	eval "${node_id}set='set'";
	eval "set_node_value $node_id $value";
	eval "set_node_left $node_id $right";
	eval "set_node_right $node_id $right";
}

# Inserts a value into a tree with a root node with identifier '$id'.
# If the node, hence the tree does not exist it creates it.
# If the root node is at the either end of the list you'll reach the
# worst case complexity of O(N), where N is the number of elements in 
# the tree. (Average case will be 0(logN).)
tree_insert() {
	local id="$1"
	local value="$2";
	# If id does not exist, create it
	if [ -z "$(eval "echo \$${id}set")" ]; then
		eval "new_node $id $value";
	# If id exists and the value inserted is less than or equal to 
	# the id's node's value. 
	# - Go down the left branch
	elif [[ $value -le $(${id}.getValue) ]]; then
		# Go down to an existing left node if it exists, otherwise
		# create it.
		if [ "$(eval ${id}.getLeftChild)xxx" != "xxx" ]; then
			tree_insert $(eval ${id}.getLeftChild) $value
		else
			local uid=$(gen_uid);
			tree_insert $uid $value;
			set_node_left $id $uid;
		fi
	# Else go down the right branch as the value inserted is larger
	# than the id node's value.
	else 
		# Go down the right node if it exists, else create it
		if [ "$(eval ${id}.getRightChild)xxx" != "xxx" ]; then
			tree_insert $(eval ${id}.getRightChild) $value
		else
			local uid=$(gen_uid);
			tree_insert $uid $value;
			set_node_right $id $uid;
		fi
	fi
}

# Insert an unsorted list of numbers into a binary search tree
for i in 10 4 16 1 7 12; do
	tree_insert bst $i;
done

# Print the binary search tree out in order
print_binary_search_tree bst
