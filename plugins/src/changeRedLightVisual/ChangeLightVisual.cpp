#include <boost/bind.hpp>
#include <gazebo/rendering/Visual.hh>
#include <gazebo/common/common.hh>
#include <ignition/transport/Node.hh>
#include "gazebo/common/Plugin.hh"
#include "gazebo/transport/Node.hh"

namespace gazebo
{
    class ChangeRedLightVisualPlugin : public VisualPlugin
    {
    public:
        void Load(rendering::VisualPtr _parent, sdf::ElementPtr _sdf) override
        {
            gzmsg << "Loading nav lights visuals plugin";
            this->model = _parent; //Initialize parent model element
            // Subscribe to ContainPlugin output
            std::string topic("mis9/contain");
            std::function<void(const ignition::msgs::Boolean &)> cb =
                [ = ](const ignition::msgs::Boolean & _msg)
            {
                ChangeRedLightVisualPlugin::OnContainPluginMsg(_msg);
            };
            const bool containSub = this->node.Subscribe(topic, cb);
            if (!containSub)
            {
                gzerr << "Failed to subscribe to [" << topic << "]\n";
            }

        }

        void OnContainPluginMsg(const ignition::msgs::Boolean &_msg)
        {
            common::Color red(1, 0, 0);
            common::Color redOff(1, 0, 0, 0.5);
            if (_msg.data())
            {
                gzmsg << "Setting visual to on\n";
                this->model->SetAmbient(red);
                this->model->SetDiffuse(red);
                this->model->SetEmissive(red);
            }
            else
            {
                gzmsg << "Setting visual to off\n";
                this->model->SetAmbient(redOff);
                this->model->SetDiffuse(redOff);
                this->model->SetEmissive(redOff);
            }
        }

    private:
        ignition::transport::Node node;
        rendering::VisualPtr model;
    };
    GZ_REGISTER_VISUAL_PLUGIN(ChangeRedLightVisualPlugin);
}