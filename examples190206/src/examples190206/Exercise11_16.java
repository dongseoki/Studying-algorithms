package examples190206;

import java.text.DecimalFormat;

public class Exercise11_16 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String data = "123,456,789.5";
		DecimalFormat df = new DecimalFormat("#,###.##");
		DecimalFormat df2 = new DecimalFormat("#,####");
		try {
			Number num =df.parse(data);
			double d = num.doubleValue();
			System.out.println("data:" + data);
			System.out.println("반올림:"+ Math.round(d));
			System.out.println("만단위:"+ df2.format(d));
		} catch (Exception e) {
			// TODO: handle exception
		}
	}

}
