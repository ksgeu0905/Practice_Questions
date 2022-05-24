priority_queue<int,vector<int>,greater<int>> pick_up,drop_off;
map<int,int>pick,drop;
int last_station=INT_MIN;
for(int i=0;i<trips.size();i++){
last_station=max(last_station,trips[i][2]);
pick_up.push(trips[i][1]);
drop_off.push(trips[i][2]);
pick[trips[i][1]]+=trips[i][0];
drop[trips[i][2]]+=trips[i][0];
}
int passenger=0;
for(int i=0;i<=last_station;i++){
if(!pick_up.empty() && i==pick_up.top()){
passenger+=pick[i];
while(i==pick_up.top())
pick_up.pop();
}
if(!drop_off.empty() && i==drop_off.top()){
passenger-=drop[i];
while(i==drop_off.top())
drop_off.pop();
}
if(passenger>capacity)
return false;