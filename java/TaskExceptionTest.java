import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

public class TaskExceptionTest {
   private static int TASK_COUNT = 3;
   static class OverCountException extends RuntimeException {
      private static final long serialVersionUID = 2221L;
   }
   static class Task implements Runnable {
      private static AtomicInteger counter = new AtomicInteger();
      @Override
      public void run() {
         int count = counter.getAndIncrement();
         System.out.print(count);
         if (count % 2 == 0) {
            throw new OverCountException();
         }
      }
   }
   public static void main(String[] args) {
      ScheduledExecutorService execSrv = Executors.newScheduledThreadPool(1);
      Task task = new Task();
      try {
         List<ScheduledFuture<?>> futureList = new ArrayList<ScheduledFuture<?>>();
         for (int i = 0; i < TASK_COUNT; i++) {
            futureList.add(execSrv.scheduleAtFixedRate(task, 0, 10, TimeUnit.MILLISECONDS));
         }
         for (ScheduledFuture<?> future : futureList) {
            try {
                future.get();
            } catch (InterruptedException e) {
                System.out.print(-3);
            } catch (ExecutionException e) {
                System.out.print(-2);
            } catch (OverCountException e) {
                System.out.print(-1);
            }
         }
      } finally {
         execSrv.shutdown();
      }
   }
}
