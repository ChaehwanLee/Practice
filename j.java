class JavaApp {
	public static void main(String[] args) {
		Point3D point3d = new Point3D();    // Point3D() 생성자로 초기화 및 인스턴스 생성
		System.out.println("point3d.x=" + point3d.x);
		System.out.println("point3d.y=" + point3d.y);
		System.out.println("point3d.z=" + point3d.z);
	}
}

class Point {
	int x = 10;
	int y = 20;

	Point(int x, int y) {
		// 생성자의 첫줄에 다른 생성자를 호출하지 않았기 때문에,
		// 컴파일러가 이 부분에 super()를 호출합니다.
		// 부모 클래스이므로 Object 클래스의 super()가 호출됩니다.
		this.x = x;
		this.y = y;
	}
}

class Point3D extends Point {
	int z = 30;

	Point3D() {
		this(100, 200, 300);	// 자신의 클래스의 또다른 생성자 호출
	}

	Point3D(int x, int y, int z) {
		super(x, y);	// 부모 클래스 생성자 호출
		this.z = z;
	}	
}