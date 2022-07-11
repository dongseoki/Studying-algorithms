//package baekjoon;
//
//import java.util.HashMap;
//import java.util.Iterator;
//import java.util.Map;
//import java.util.Objects;
//
//class Identifier {
//    private long X;
//    private long visited;
//
//    public Identifier(long X, long visited) {
//        this.X = X;
//        this.visited = visited;
//    }
//
//    @Override
//    public boolean equals(Object o) {
//        if(this == o) return true;
//        if(o == null || getClass() != o.getClass()) return false;
//
//        Identifier other = (Identifier)o;
//
//        return other.X == X && other.visited == visited;
//    }
//
//    @Override
//    public int hashCode() {
//        return Objects.hash(X, visited); // import java.util.Objects; 가 필요함
//    }
//
//    @Override
//    public String toString() {
//        return "X " + this.X + " V " + this.visited + " | ";
//    }
//}
//public class test {
//    public static void main(String[] args) {
//
//        // custom  HashMap Test.
//        Map<Identifier, Long> testMap = new HashMap<Identifier, Long>();
//        testMap.put(new Identifier(1,2), 100L);
//        testMap.put(new Identifier(2,4), 300L);
//        testMap.put(new Identifier(1,2), 300L);
//
//        Iterator<Identifier> keys = testMap.keySet().iterator();
//        while(keys.hasNext()){
//            Identifier item = keys.next();
//
//            System.out.println(item.toString() + testMap.get(item));
//        }
//    }
//}
