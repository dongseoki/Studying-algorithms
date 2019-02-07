import java.util.*;
import java.text.*;

class Exercise11_15 
{
	static int paycheckCount(Calendar from, Calendar to) {
		/*
		  (1) �˸��� �ڵ带 �־� �ϼ��Ͻÿ�.

		   1. from �Ǵ� to�� null�̸� 0�� ��ȯ�Ѵ�.
		   2. from�� to�� ���� ��¥�� 21���̸� 1�� ��ȯ�Ѵ�.
		   3. to�� from�� �� ���� �������� ����ؼ� ���� monDiff�� ��´�.
		   4. monDiff�� �����̸� 0�� ��ȯ�Ѵ�.
		   5. ���� from�� ��(DAY_OF_MONTH)�� 21���̰ų� �����̰�
                      to�� ��(DAY_OF_MONTH)�� 21���̰ų� �����̸� monDiff�� ���� 1 ������Ų��.
		   6. ���� from�� ��(DAY_OF_MONTH)�� 21�� ���İ�
                      to�� ��(DAY_OF_MONTH)�� 21�� �����̸� monDiff�� ���� 1 ���ҽ�Ų��.
		*/

		return monDiff;		
	}
	
	static void printResult(Calendar from, Calendar to) {
		Date fromDate = from.getTime();
		Date toDate   = to.getTime();

		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");

		System.out.print(sdf.format(fromDate)+" ~ "
                                     +sdf.format(toDate)+":");
		System.out.println(paycheckCount(from, to));
	}

	public static void main(String[] args) 
	{
		Calendar fromCal = Calendar.getInstance();
		Calendar toCal   = Calendar.getInstance();

		fromCal.set(2010,0,1);
		toCal.set(2010,0,1);
		printResult(fromCal, toCal);

		fromCal.set(2010,0,21);
		toCal.set(2010,0,21);
		printResult(fromCal, toCal);

		fromCal.set(2010,0,1);
		toCal.set(2010,2,1);
		printResult(fromCal, toCal);

		fromCal.set(2010,0,1);
		toCal.set(2010,2,23);
		printResult(fromCal, toCal);

		fromCal.set(2010,0,23);
		toCal.set(2010,2,21);
		printResult(fromCal, toCal);

		fromCal.set(2011,0,22);
		toCal.set(2010,2,21);
		printResult(fromCal, toCal);
	
	}
}
