import java.util.List;
import java.util.ArrayList;

/*
ArrayList methods:
	List<String> list = new ArrayList<>(); // init
	void add(E e); // add a elemnet in the last of the ArrayList;
	void add(int index, E e); // add a elemnet in the index position;
	void remove(int index, E e); // add a elemnet in the index position;
	int size(); // get the list's size
*/
public class List_test_1 {
	public static void main(String[] args){
		List<String> list = new ArrayList<>();

		list.add("apple");
		list.add("pear");
		list.add(0, "apple");
		for(int i=0; i<list.size(); i++){
			String s = list.get(i);
			System.out.print(i+": ");
			System.out.println(s);
		}
		System.out.print("\n\n");

		list.remove(list.get(1));
		for(int i=0; i<list.size(); i++){
			String s = list.get(i);
			System.out.print(i+": ");
			System.out.println(s);
		}

		System.out.print("\n");
	}
}
