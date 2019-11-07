

public class Array<E> {    // 这就是c++的类模版  //
    private E[] data;
    private int size;

    //构造函数，  传入数组的容量 capacity 构造函数
    public Array(int capacity) {
        data = (E[]) new Object[capacity];
        size = 0;
    }

    // 无参数的构造函数， 默认数组的容量 capacity = 10
    public Array() {
        this(10);
    }

    // 获取数组中元素的个数
    public int getSize() {
        return size;
    }

    // 获取数组的容量
    public int getCapacity(){
        return data.length;
    }

    // 返回数组是否为空
    public boolean isEmpty(){
        return size == 0;
    }


    // 向所有元素后添加一个新元素
    public void addLast(E e){
        add(size,e);
    }

    // 在所有元素前添加一个新元素
    public void addFirst(E e){
        add(0,e);
    }


    // 在index 个位置插入一个新元素 e
    public void add(int index, E e){

        if(index < 0 || index > size)
            throw new IllegalArgumentException("ADD failed, Array is full : size >= 0 || size <= index");

        if(size == data.length)
            resize(2 * data.length);

        for(int i = size-1; i>= index; i--)
            data[i+1] = data[i];


        data[index] = e;
        size++;
    }


    // 获取 index 索引位置的元素
    E get(int index){
        if(index <0 || index >= size)
            throw new IllegalArgumentException("get failed. Index is illegal");
        return data[index];
    }

    // 修改index 索引位置的元素为e
    void set(int index, E e){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("set failed . Index is illegal");
        data[index] = e;
    }


    //查找数组中是否有元素e
    public boolean contains(E e){
        for(int i = 0; i< size ; i++){
            if( data[i].equals(e))
                return true;
        }
        return false;
    }

    // 查找数组中元素e 所在的索引， 如果不存在元素e， 则返回-1
    public int find(E e){
        for(int i = 0; i< size ; i++){
            if( data[i].equals(e))          // equals()是值比较， == 是引用比较
                return i;
        }
        return -1;
    }

    // 从数组中删除index位置元素， 返回删除的元素的值
    public E remove(int index){
        if(index <0 || index >= size)
            throw new IllegalArgumentException("Remove failed. Index is illegal");

        E ret = data[index];

        for(int i = index+1; i < size ;i++ )
            data[i -1]  = data[i];

        size--;
        data[size] = null;

        if(size == data.length /4 && data.length/2 != 0)
            resize(data.length/2);

        return ret;
    }

    // 从数组中删除第一个元素， 返回删除元素的值
    public E removeFirte(){
        return remove(0);
    }

    //从数组中删除最后一个元素，  返回删除元素的值
    public E removeLast(){
        return remove(size-1);
    }

    //从数组中删除元素e
    public boolean removeElement(E e) {
        int index = find(e);
        if (index != -1) {
            remove(index);
            return true;
        }
        return false;
    }



    @Override
    public String toString(){   // 修改了默认输出，就是相当于重定义了 cout <<
        StringBuilder res = new StringBuilder();

        res.append(String.format("Array: size = %d, capacity = %d\n",size, data.length));
        res.append('[');
        for(int i = 0; i<size; i++){
            res.append(data[i]);
            if(i != size-1)
                res.append(", ");
        }
        res.append(']');
        return res.toString();

    }


    private void resize(int newCapacity){
        E[] newData = (E[]) new Object[newCapacity];
        for(int i = 0; i < size; i++)
            newData[i] = data[i];
        data = newData;
    }

};

