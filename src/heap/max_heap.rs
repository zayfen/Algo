
struct Node<T> {
    value: T,
    left: Box<T>,
    right: Box<T>,
    parent: Box<T>
}

// priofity queue
struct PriorityQueue<T> {
    root: Node<T>,
    size: int
}

impl<T> PriorityQueue<T> {
    fn getFront(&self) -> Option<T> {
        if let self.root.value = Some {
            return Some(&self.root.value)
        }
        
    }

}
