
class oddeventMonitor{
	public static final boolean odd_turn = true;
	public static final boolean even_turn = false;
	private boolean turn = odd_turn;
	
	public synchronized void waitTurn(boolean oldTurn){
		while(turn!=oldTurn){
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public synchronized void toggleTurn(){
		turn ^= true;
		notify();
	} 
}

class oddThread extends Thread{
	private oddeventMonitor monitor;
	public oddThread(oddeventMonitor monitor){
		this.monitor = monitor;
	}
	@Override
	public void run(){
		for(int i=1;i<100;i=i+2){
			monitor.waitTurn(oddeventMonitor.odd_turn);
			System.out.println(i);
			monitor.toggleTurn();
		}
	}
}
