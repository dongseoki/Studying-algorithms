package test;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String data = "2fasdf.mimmasdf.mimm";
      String temp = new String(data);
      String stringnum=" ";
      int si_filename = 0; //start index of filename;
      char a= ' ';
      for(int i=0;i<temp.length();i++){
          a= temp.charAt(i);
          if(a<'0' || '9'<a){
              stringnum = temp.substring(0,i);
              si_filename = i;
              break;
          }
      }
      System.out.println(stringnum);
       int num =    Integer.parseInt(stringnum);
      // System.out.println("num/si_filename="+ num+"/"+si_filename);
      //Log.d("SAMPLEHTTP", "num/si_filename="+num+ "/"+si_filename);
      //indexOf(String str, int fromIndex)
      //Returns the index within this string of the first occurrence of the specified substring, starting at the specified index

      int index_mimm;
      int s_index=si_filename;

      index_mimm = temp.indexOf(".mimm",s_index);
      if(index_mimm ==-1) {
          return;// 끝내기.
      }
      System.out.println(temp.substring(s_index,index_mimm));
      index_mimm +=5;//pass .mimm
      s_index = index_mimm;
      
      while(true) {
    	  index_mimm = temp.indexOf(".mimm",s_index);
          if(index_mimm ==-1) {
              break;// 끝내기.
          }
          System.out.println(temp.substring(s_index,index_mimm));
          index_mimm +=5;//pass .mimm
          s_index = index_mimm;
      }
      
	}

}
