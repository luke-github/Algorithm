 public class oddMonitor{
	public static final boolean odd_turn = true;
	public static final boolean even_turn = false;
	private boolean turn = odd_turn;
	public synchronized void waitTurn(boolean oldturn) throws InterruptedException{
		while(turn!=oldturn){
			wait();
		}
	}
	public synchronized void toggleTurn(){
		turn ^= true;
		notify();
	}
}

class oddThread extends Thread{
	public final oddMonitor monitor;
	public oddThread(oddMonitor monitor){
		this.monitor = monitor;
	}
	@Override
	public void run(){
		for(int i=1;i<100;i=i+2){
			monitor.waitTurn(oddMonitor.odd_turn);
			System.out.println(i);
			monitor.toggleTurn();
		}
	}
}
