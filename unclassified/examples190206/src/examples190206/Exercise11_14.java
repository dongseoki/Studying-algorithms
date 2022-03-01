package examples190206;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Exercise11_14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd은  2번째 일요일입니다.");
		Calendar date = Calendar.getInstance();
		for(int i=0;i<12;i++) {
			date.set(2010,i,1);
			int num =date.get(Calendar.DAY_OF_WEEK);
			if(num ==1) {
				date.set(2010, i, 8);
			}
			else {
				date.set(2010, i, 16-num);
			}
			Date day = date.getTime();
			System.out.println(sdf.format(day));
		}
	}

}
