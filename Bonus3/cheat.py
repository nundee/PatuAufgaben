import pandas as pd
import numpy as np
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn import tree
import matplotlib.pyplot as plt

# Hint: This one we already solved for you ;)
df = pd.read_csv("train.csv")  #make sure "train.csv" is located in the right place!

X = df.drop(['y'], axis=1).to_numpy()
y = df['y'].to_numpy()

np.random.seed(42) #don't change!
max_accuracy=0.0
best_model=None
for mdepth in range(2,4,5):
    for j in range(20):
        X_train, X_test, y_train, y_test = train_test_split(X,y,train_size=0.8)
        mdl = DecisionTreeClassifier(max_depth=mdepth).fit(X_train,y_train)
        y_pred_train = mdl.predict(X_train)
        y_pred_test  = mdl.predict(X_test)
        y_pred_total = mdl.predict(X)
        a=accuracy_score(y_test,y_pred_test)
        if a > max_accuracy:
            best_model=mdl
            max_accuracy=a
        #print(mdepth, "try",j,':',
        #  'score train %.5f' % accuracy_score(y_train,y_pred_train), 
        #  '| score test %.5f' % a,
        #  '| score total %.5f' % accuracy_score(y,y_pred_total))

#X_train, X_test, y_train, y_test = train_test_split(X,y,train_size=0.8)

#clf=DecisionTreeClassifier(max_depth=2).fit(X_train,y_train)
#y_pred_dt=clf.predict_proba(X_test)


#tree.plot_tree(best_model, filled=True, feature_names=df.columns)
#plt.show()

y_pred_dt=best_model.predict(X_test)
print("accuracy dt =",accuracy_score(y_test,y_pred_dt))

from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.neural_network import MLPClassifier

rfc=RandomForestClassifier(n_estimators=500, max_depth=2)
rfc.fit(X_train,y_train)
y_pred_rf=rfc.predict(X_test)
print("accuracy rf =",accuracy_score(y_test,y_pred_rf))

gbc=GradientBoostingClassifier()
gbc.fit(X_train,y_train)
y_pred_gb=gbc.predict(X_test)
print("accuracy gb =",accuracy_score(y_test,y_pred_gb))

mlpc=MLPClassifier(hidden_layer_sizes=(10,4,3,2), max_iter=10000).fit(X_train,y_train)
mlpc.fit(X_train,y_train)
y_pred_mlp=mlpc.predict(X_test)
print("accuracy mlp =",accuracy_score(y_test,y_pred_mlp))


def cheater(x):
    x1,x2,x3=x
    if x1 <=7: #6.871:
        if x3 <=4: #3.624:
            return 0.0 #np.argmax([136.0/180,43.0/180])
        else:
            return 1.0 #np.argmax([63.0/312, 249/312])
    else:
        if x2 <= 2.465:
            return 0.0 #np.argmax([27.0/40,13.0/40])
        else:
            return 0.0 #np.argmax([222.0/268, 46.0/268])

y_pred_ch=np.array([cheater(x) for x in X_test])
print("accuracy cheater =", accuracy_score(y_test,y_pred_ch))

X_final = pd.read_csv("X_final.csv").to_numpy()

y_final_dt = best_model.predict(X_final).astype(int)
y_final_rf = rfc.predict(X_final).astype(int)
y_final_gb = gbc.predict(X_final).astype(int)
y_final_mlp = mlpc.predict(X_final).astype(int)
y_final_cheat=np.array([cheater(x) for x in X_final], dtype=int)

for i in range(len(y_final_dt)):
    print(f"Der Punkt in der Reihe {i} ist vom Typ {[y_final_dt[i], y_final_rf[i],y_final_gb[i], y_final_mlp[i], y_final_cheat[i]]}")
