One array given Two Player playing game 1 player ram can pick any element from array and 
shyam pick only from left pick you have to maximize differencce between Ram-shyam Ram start first

start se chalu kro priority queue me dalo dono elemnt jo chota hoga nikal jayega fir 2 add kro aisa hi 

// aray is always even
pq->  min_priority_queue
for(int i=0;i<n;i+=2)
{
  pq.push(a[i]);
  pq.push(a[i+1]);
  pq.pop();
}

finally all elemnt left in pq add and return ans✅